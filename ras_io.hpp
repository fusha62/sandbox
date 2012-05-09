#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>

typedef struct
{
  /* ヘッダ情報の保持 */
  int magic;
  int width;
  int high;
  int depth;
  int length;
  int type;
  int maptype;
  int maplength;
  int colormap_length; // カラーマップ用
  boost::numeric::ublas::matrix<int> image; // 画像データ用行列
} RASTER_FORMAT;

int convEndian(void *inpt, size_t s){
  /*
   エンディアン変換用関数
   参考
   初心者のプログラミング体験記
   ビッグ or リトル。エンディアン変換！【C言語】
   http://torasukenote.blog120.fc2.com/blog-entry-106.html
  */

  int count;
  char tmp[16];

  /* tmpデータにinptを一時確保 */
  for(count=0; count<s; count++)
    tmp[count] = ((char *)inpt)[count];

  /* tmpデータを逆方向にしてinptに代入 */
  for(count=0; count<s; count++)
    ((char *)inpt)[count] = tmp[s-count-1];

  return 1;
}

void ras_read(RASTER_FORMAT *ras, char *file_name){
  /*
    RasterFormatのヘッダとカラーマップ読み込み，
    画像の二次元配列作成．
    及びヘッダとカラーマップ出力．
   */
  
  /* 変数定義 */
  std::ifstream ifs;
  int ras_magic;
  int ras_width;
  int ras_high;
  int ras_depth;
  int ras_length;
  int ras_type;
  int ras_maptype;
  int ras_maplength;
  /* 変数定義終わり */

  /* ファイルオープン */
  ifs.open(file_name);
  
  /* ファイルから各変数への読み出し */
  ifs.read((char *)&ras_magic, sizeof(int));
  convEndian(&ras_magic,sizeof(int));
  ras->magic = ras_magic;

  ifs.read((char *)&ras_width, sizeof(int));
  convEndian(&ras_width, sizeof(int));
  ras->width = ras_width;

  ifs.read((char *)&ras_high, sizeof(int));
  convEndian(&ras_high, sizeof(int));
  ras->high = ras_high;

  ifs.read((char *)&ras_depth, sizeof(int));
  convEndian(&ras_depth, sizeof(int));
  ras->depth = ras_depth;

  ifs.read((char *)&ras_length, sizeof(int));
  convEndian(&ras_length, sizeof(int));
  ras->length = ras_length;

  ifs.read((char *)&ras_type, sizeof(int));
  convEndian(&ras_type, sizeof(int));
  ras->type = ras_type;
  
  ifs.read((char *)&ras_maptype, sizeof(int));
  convEndian(&ras_maptype, sizeof(int));
  ras->maptype = ras_maptype;
  
  ifs.read((char *)&ras_maplength, sizeof(int));
  convEndian(&ras_maplength, sizeof(int));
  ras->maplength = ras_maplength;
 
  {
    /* RGBのマップ長を分割して，1つのマップ長を計算 */
    int colormap_length;
    colormap_length = (int)(ras_maplength/3);
    ras->colormap_length = colormap_length;

    /* RGBカラーマップを読み込み */
    int i,j;
    int map;
    for (i=0; i<colormap_length; i++)
      map = ifs.get();
    for (i=0; i<colormap_length; i++)
      map = ifs.get();
    for (i=0; i<colormap_length; i++)
      map = ifs.get();

    /* 画像データ格納メモリを確保 */
    //boost::numeric::ublas::matrix<int> ras_image(ras_high,ras_width);
    ras->image.resize(ras_high,ras_width);

    /* 画像データを読み込み */
    for (i=0; i<ras_high; i++)
      for (j=0; j<ras_width; j++){
	ras->image(i,j)=ifs.get();
      }

    //ras->image =ras_image;
  }
  ifs.close();
}

void ras_write(RASTER_FORMAT *ras, char *file_name){
  /*
    RasterFormatのヘッダとカラーマップ読み込み，
    画像の二次元配列作成．
    及びヘッダとカラーマップ出力．
   */
  
  /* 変数定義 */
  std::ofstream fp;
  int ras_magic;
  int ras_width;
  int ras_high;
  int ras_depth;
  int ras_length;
  int ras_type;
  int ras_maptype;
  int ras_maplength;
  /* 変数定義終わり */

  /* ファイルオープン */
  fp.open(file_name);
  
  /* 各変数からファイルへの書き出し */
  ras_magic = ras->magic;
  convEndian(&ras_magic, sizeof(int));
  fp.write((char *)&ras_magic, sizeof(int));
  
  ras_width = ras->width;
  convEndian(&ras_width, sizeof(int));
  fp.write((char *)&ras_width, sizeof(int));
  
  ras_high = ras->high;
  convEndian(&ras_high, sizeof(int));
  fp.write((char *)&ras_high, sizeof(int));
  
  ras_depth = ras->depth;
  convEndian(&ras_depth,sizeof(int));
  fp.write((char *)&ras_depth,sizeof(int));

  ras_length = ras->length;
  convEndian(&ras_length,sizeof(int));
  fp.write((char *)&ras_length,sizeof(int));
  
  ras_type = ras->type;
  convEndian(&ras_type,sizeof(int));
  fp.write((char *)&ras_type,sizeof(int));
  
  ras_maptype = ras-> maptype;
  convEndian(&ras_maptype,sizeof(int));
  fp.write((char *)&ras_type,sizeof(int));

  ras_maplength = ras->maplength;
  convEndian(&ras_maplength,sizeof(int));
  fp.write((char *)&ras_maplength,sizeof(int));

  {
    /* RGBのマップ長を分割して，1つのマップ長を計算 */
    int colormap_length;
    colormap_length = (int)(ras->maplength/3);
    
    /* RGBカラーマップを書き込み */
    int i,j;
    for (i=0; i<colormap_length; i++)
      fp.put(i);
    for (i=0; i<colormap_length; i++)
      fp.put(i);
    for (i=0; i<colormap_length; i++)
      fp.put(i);

    /* 画像データを書き込み */
    for (i=0; i<ras->high; i++)
      for (j=0; j<ras->width; j++){
        fp.put(ras->image(i,j));
      }
  }

  fp.close();
}

