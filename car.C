/*Tyler Allen
CS111
Lab 12-1
4/14/15
This program will output files based on an input file*/

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main(){

  string car;
  int total=0;
  int count =0;
  int miles;
  int gallons;
  int totalGallons=0;

  ifstream inFile;
  ofstream outFile;

  inFile.open("car.dat");

  outFile.open("carout.dat");

  if(!inFile)
    {
      outFile<<"Cannot open the file"<<endl;
    }
  else
    {
      inFile>>car;
      inFile>>miles;
      inFile>>gallons;
      outFile<<left<<setw(10)<<"Model Name"<<right<<setw(25)<<"Miles Driven"<<setw(25)<<"Gallons of Gas Used"<<setw(25)<<"MPG"<<endl;

      while(inFile)
	{
	  outFile<<left<<setw(10)<<car<<right<<setw(25)<<miles<<setw(25)<<gallons<<fixed<<setprecision(2)<<setw(25)<<(double)miles/gallons<<endl;
	  total+=miles;
	  totalGallons+=gallons;
	  count++;
	  inFile>>car;
	  inFile>>miles;
	  inFile>>gallons;
	}
      outFile<<endl;
      if(count!=0)
	{
	outFile<<"Total Miles Driven: "<<total<<" miles"<<endl;
      outFile<<"Total Gallons of Gas Used: "<<totalGallons<<" gallons"<<endl;
      outFile<<"Average MPG: "<<fixed<<setprecision(2)<<(double)total/totalGallons<<" miles per gallon"<<endl;
	}
      else
	{
	  outFile<<"No cars were in the input file.";
	}
      inFile.close();
    }

  outFile.close();
  return 0;
}
