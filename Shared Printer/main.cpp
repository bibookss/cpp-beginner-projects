#include <iostream>
#include <queue>
#include <ctime>
#include <iomanip>
#include <unistd.h>
using namespace std;

struct Job {
    string Id;
    string userName;
    int numPages;
};

class Printer{
    private: 
    queue<Job> jobs;
    int jobId = 0;
    size_t maxPrint = 5;

    public:
    bool addJob(string, int);
    void printJob();
    string generateJobId();
    void runPrinter();
};

string Printer::generateJobId(){
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    string year, month, day, sJobId;

    year = to_string(1900 + local_time->tm_year);
    month = to_string(1 + local_time->tm_mon);
    day = to_string(local_time->tm_mday);

    ostringstream m, d, j;
    m << setw(2) << setfill('0') << month;
    month = m.str();

    d << setw(2) << setfill('0') << day;
    day = d.str();

    j << setw(5) << setfill('0') << jobId;
    sJobId = j.str();

    jobId++;

    return year + month + day + sJobId;
}

bool Printer::addJob(string name, int num){
    if (jobs.size() == maxPrint){
        cout << "The queue is full.\n";
        return false;
    } else {
        Job tmp;
        tmp.Id = generateJobId();
        tmp.userName = name;
        tmp.numPages = num;

        jobs.push(tmp);

        cout << "Print job successfully added to queue.\n";

        return true;
    }
}

void Printer::printJob(){
    if (jobs.empty()){
        cout << "No printing jobs in queue.\n";
    } else {
        cout << "Printing...\n" << "Job ID: " << jobs.front().Id << endl
             << "User: " << jobs.front().userName << endl
             << "Pages: " << jobs.front().numPages;
        sleep(2);
        jobs.pop();
    }
}

void Printer::runPrinter(){
    while(!jobs.empty()){
        printJob();
    }
}


int main(){
    Printer p;
    p.addJob("A", 50);
    p.addJob("b", 50);
    p.addJob("c", 50);
    p.addJob("d", 50);
    p.addJob("e", 50);
    p.addJob("f", 50);
    p.runPrinter();
}