using System;
using System.Linq;

class Program
{

static void Main(){

string[] azusa =
{
	"gokinyan",
	"azunyan",
	"nakanoazusa",
	"azusa",
	"azu",
};

var ret = from x in azusa
    	  where x[2] == 'u'
	  select x;

foreach (var e in ret)
{
	Console.WriteLine(e);
}

}

}