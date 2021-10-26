#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
#include<random>
#include<algorithm>

using namespace std; 

struct MyArray{
    string color;
    int number;
};

void ReadInputFile();                                   
double RandomDraw(int range);                                 
void Simulation(int times);
int Colordrawn(int numb);

int DrawnTimes;                                              
int range;
int NumberOfColor;
vector<MyArray> bulb;
ifstream loadfile;

void ReadInputFile(){
    int number;
    string color;
    
    bulb.push_back(MyArray());
    if (loadfile.fail()){
        cout << "Your file did not work" << endl;
    }
    else {
       int i = 0;
        while (loadfile)
        {     
            if (loadfile >> color >> number){
                 bulb.push_back(MyArray());
                 bulb[i].color = color;
                 bulb[i].number = number;
                 cout <<bulb[i].color << "--"<< bulb[i].number <<endl;
                 i++;
            }
            else {
                cout << "End of list" << endl;
                loadfile >> color;
                DrawnTimes = stoi(color);
                range = i; 
            }
        }
    }
}
    

double RandomDraw(int range){
    int Result = 0;
    int ncolor;
    int NoOfDrawnBulb[range];
    double Sum = 0;
    srand(time(0));

    for (int i=0; i<=range;i++){
        NoOfDrawnBulb[i]=0;
    }
    cout << "-----Drawing time:-----" << endl;
    for (int i = 1; i <= DrawnTimes; i++){
        Result = (rand() % range );
        //cout << "Bulb color " << bulb[Result].color << " is Drawn" << endl;
        if (bulb[Result].number > 0){
            NoOfDrawnBulb[Result]++;
            bulb[Result].number--;
            // cout << bulb[Result].color <<" ** " << bulb[Result].number<<" left " << endl;
        }
        else{
            DrawnTimes++;
        }      
    }
    for (int i =0; i < range; i++){
        bulb[i].number=NoOfDrawnBulb[i]; //Get number of drawn bulb
        cout << bulb[i].color <<" ** " << bulb[i].number<<" draw " << endl;
    }
    sort(NoOfDrawnBulb,NoOfDrawnBulb+range);
    for (int i = 0; i < range; i++){
        while(i < range  && NoOfDrawnBulb[i] == NoOfDrawnBulb[i+1])
            i++;
        cout << "Unique numbers --" << NoOfDrawnBulb[i]<<endl;
        ncolor = Colordrawn(NoOfDrawnBulb[i]);
        Sum += NoOfDrawnBulb[i]; 
    }
    cout <<"Number of colors drawn --"<< ncolor << endl;
    return Sum;
}

int Colordrawn(int numb){
    for (int i = 0; i <= range; i++){
        if(bulb[i].number == numb && bulb[i].number !=0 && NumberOfColor <range)
            ++NumberOfColor;
    }
    return NumberOfColor;
}

int main(int argc, char* argv[]){
    string file = argv[1];
    int iter =1;
    int iterations = stoi(argv[2]);
    double TUniqueNumber = 0;
    
    cout << "ERROR!!:: Run the program with your 'input' + 'sampletimes' " << endl;
    if (argc > 1 ){
        cout << "argv[1]" << argv[1] << "argv[2]" << argv[2]<< endl;
    } 
    else {
        cout << " Nofile name Entered. Exiting..." << endl;
        return -1;
    }


    while(iter < iterations){
        NumberOfColor = 0;
        loadfile.open(file);
        ReadInputFile();
        TUniqueNumber += RandomDraw(range);
        iter++;
        loadfile.close();
    }
    cout << "******\nExpected Number after running: "<<iterations 
    << " simulations is: " << TUniqueNumber/iterations << endl;
    return 0;
}
