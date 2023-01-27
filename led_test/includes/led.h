#include <iostream>
#include <fstream>

using namespace std;

#ifndef Led_h
#define Led_h

class Led
{
  public:
    ifstream fin("value.txt");
    if (!fin)
    {
      cerr << "파일을 찾을 수 없음" << endl;
      exit(100);
    }
    return 0;

  private:
    int _led;
};

#endif



string out_line;
ofstream out("/sys/class/gpio/gpio487/value");
for(int i=0;i<=1;i ){
    cin>>out_line;
    out<<out_line<<endl;
}

out.close();