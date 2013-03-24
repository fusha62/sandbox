using System;

class CharLen
{
	public static void Main()
	{
		Console.WriteLine("文字を入力");
		var s = Console.ReadLine();
		Console.WriteLine("{0} ：文字数 {1}", s, s.Length);
	}
}