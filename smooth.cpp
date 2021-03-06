#include <iostream>
#include <algorithm>
#include <math.h>
#include "ras_io.hpp"
#include <boost/thread.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

int main(int argc, char *argv[]){
  RASTER_FORMAT inras, outras; //画像フォーマット
  int shikichi; //しきい値

  // 引数チェック
  if(argc==1) {
    printf("./smooth [infile] [outfile]\n");
    exit(0);
  }

  // rasファイルから画像データの取り込み
  ras_read(&inras, argv[1]);

  // 画像データの基本情報をコピー
  outras.magic = inras.magic;
  outras.width = inras.width;
  outras.high = inras.high;
  outras.depth = inras.depth;
  outras.length = inras.length;
  outras.type = inras.type;
  outras.maptype = inras.maptype;
  outras.maplength = inras.maplength;
  outras.colormap_length = inras.colormap_length;
  
  // 作業用メモリの動的確保
  boost::numeric::ublas::matrix<int> outras_image(outras.high,outras.width);

  // 平滑化フィルタの定義
  boost::numeric::ublas::matrix<int> smooth(7,7);
  for (int i=0; i<smooth.size1(); i++)
    for (int j=0; j<smooth.size2(); j++)
      smooth(i,j)=std::min(4-abs(3-i),4-abs(3-j));
  //std::cout << smooth << std::endl;
  
  // smooth filter
  // {{1,1,1,1,1,1,1},
  // {1,2,2,2,2,2,1},
  // {1,2,3,3,3,2,1},
  // {1,2,3,4,3,2,1},
  // {1,2,3,3,3,2,1},
  // {1,2,2,2,2,2,1},
  // {1,1,1,1,1,1,1}};
  
  // Kを求める
  double k_val;
  {
    boost::numeric::ublas::matrix<double> K(1,1);
    boost::numeric::ublas::matrix<int> yoko(1,smooth.size2());
    boost::numeric::ublas::matrix<int> tate(smooth.size1(),1);
    boost::numeric::ublas::matrix<int> tmp_mat(1,smooth.size2());
    for (int i=0; i<smooth.size1(); i++){yoko(0,i)=1; tate(i,0)=1;}
    tmp_mat = boost::numeric::ublas::prod(yoko,smooth);
    K = boost::numeric::ublas::prod(tmp_mat,tate);
    k_val = (double)K(0,0);
  }
  std::cout << k_val << std::endl;

  
  // 画像を書き出し
  outras.image = outras_image;
}
