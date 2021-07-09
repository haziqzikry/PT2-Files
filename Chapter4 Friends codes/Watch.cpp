#include <iostream>
using namespace std;

class Watch{
	int hour, minute, second;
	public:
		Watch(int the_hour, int the_minute, int the_second){
			hour=the_hour;
			minute=the_minute;
			second=the_second;
		}
		//void input();
		//void output();
		//bool equal(Watch time1, Watch time2);
		friend bool equal(Watch time1, Watch time2); //Friend functions have objects as arguments
};
//bool Watch::equal(Watch time1, Watch time2){
bool equal(Watch time1, Watch time2){
	bool check=false;
	if(time1.hour==time2.hour){
		if(time1.minute==time2.minute){
			if(time1.second==time2.second){
				check=true;
			}
		}
	}
	return check;
}

int main(){
	Watch t(14,30,16);
	Watch m(15,15,30);
	cout<<equal(t,m)<<endl; //0 false 1 true
	//cout<<m.equal(t,m)<<endl; //0 false 1 true
	//Watch w(15,15,30);
	//cout<<equal(w,m); //0 false 1 true
	return 0;
}
