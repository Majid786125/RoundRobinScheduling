#include <iostream>
using namespace std;
class Process
{
public:
    int ArrivalTime,WaitTime,BrustTime,ProcessNo,Turnaround;
    bool flag;

    Process()
    {
        ArrivalTime=0;
        WaitTime=0;
        BrustTime=0;
        ProcessNo=0;
        Turnaround=0;
        flag= false;
    }
    void Print();
};
void Process::Print()
{
    cout<<ProcessNo<<"                     "<<BrustTime<<"                 "<<WaitTime<<"                 "<<Turnaround<<endl;
}
Process init(Process P[], int N) {
    for (int i = 0; i < N; i++) {
        P[i].ArrivalTime = 0;
        cout << "Enter BrustTime of P[" << i << "]:";
        cin >> P[i].BrustTime;
        P[i].ProcessNo = i;
        P[i].flag = false;
        P[i].Turnaround=0;
    }
    return *P;
}

Process Average(Process P[],int N,int S) {
    int A[N];
    for(int i=0;i<N;i++)
    {
        A[i]=P[i].BrustTime;
    }
    int Quantum=S,T=0,G=0,Count=0,Wa=3;
    double TotalTime=0,AverageTime=0,Wait=0,TT=0;
    for(int i=0;T!=N;i++)
    {
        if(i==0)
        {
            if(A[Count]>=Quantum)
            {
                P[Count].WaitTime=0;
                A[Count]=A[Count]-Quantum;
                if(A[Count]==0)
                {
                    P[Count].flag=true;
                    T++;
                }
            }
            else
            {
                P[Count].WaitTime=0;
                Wa=A[Count];
                A[Count]=A[Count]-A[Count];
                P[Count].flag= true;
                T++;
            }
        }
        if(i > 0 && P[Count].flag == false) {
            if(A[Count]>=Quantum)
            {

                P[Count].WaitTime=Wa;
                Wa=Wa+3;
                A[Count]=A[Count]-Quantum;
                if(A[Count]==0)
                {
                    P[Count].flag=true;
                    T++;
                }
            }
            else if(A[Count]<Quantum)
            {
                P[Count].WaitTime=Wa;
                Wa=Wa+A[Count];
                A[Count]=A[Count]-A[Count];
                P[Count].flag=true;
                T++;
            }
        }
        Count++;
        if(Count>2)
        {
            Count=0;
            Wa=Wa-3;
        }
    }
    for (int i = 0; i < N; ++i) {
        P[i].Turnaround=P[i].WaitTime+P[i].BrustTime;
    }
    for (int i = 0; i < N; ++i) {
        Wait=Wait+P[i].WaitTime;
    }
    for (int i = 0; i < N; ++i) {
        TotalTime=TotalTime+P[i].BrustTime;
    }
    AverageTime=Wait/N;
    TT=(TotalTime+Wait)/N;
    cout<<endl;

    cout<<"Average Waiting Time is : "<<AverageTime<<endl;
    cout<<"Average TurnAround Time is :"<<TT<<endl;
    return *P;
}
int main() {
    int N,S;
    cout<<"Enter Number of Processes : ";
    cin>>N;
    cout<<"Enter Quantum Size : ";
    cin>>S;
    Process P[N];
    init(P,N);
    Average(P,N,S);
    cout<<endl;
    cout<<"Process No"<<"         "<<"BrustTime"<<"         "<<"WaitingTime"<<"         "<<"TurnAroundTime"<<endl;
    for (int i = 0; i < N; ++i) {
        P[i].Print();
    }
    return 0;
}