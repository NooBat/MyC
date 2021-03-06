#ifndef _EVENT
#define _EVENT

#include<string>

using namespace std;

class Event
{
private:
    string transactionCode;
    string mopCode;
    string state;
    double startTime;
    double processTime;
    double totalTime;
    bool approved;
    string name;

public:
    Event() {}

    Event(const string& transactionCode, const string& mopCode, const string& state, const double& startTime, const double& processTime, const string& name, const double& totalTime, const bool& approved = true)
    {
        this->setTransaction(transactionCode);
        this->setMOP(mopCode);
        this->setState(state);
        this->setStartTime(startTime);
        this->setProcessTime(processTime);
        this->setApproved(approved);
        this->setName(name);
        this->setTotalTime(totalTime);
    }

    bool setTransaction(const string& transactionCode)
    {
        if (transactionCode != "L" && transactionCode != "R" &&
            transactionCode != "l" && transactionCode != "r")
        {
            return false;
        }
        this->transactionCode = transactionCode;
        return true;
    }

    bool setMOP(const string& mopCode)
    {
        if (mopCode != "$" && mopCode != "C")
        {
            return false;
        }

        this->mopCode = mopCode;
        return true;
    }

    bool setState(const string& state)
    {
        /*A for arrival
          S for sign in
          L for license renewal
          R for registration renewal
          CC for cashier approval
          D for departure */
        if (state != "A" && state != "S" && state != "L" && state != "R" && state != "CC" && state != "D") return false;
        
        this->state = state;

        return true;
    }

    void setStartTime(const double& startTime)
    {
        if (startTime < 0.0) this->startTime = 0.0;
        else this->startTime = startTime;
    }

    void setProcessTime(const double& processTime)
    {
        if (processTime < 0.0) this->processTime = 0.0;
        else this->processTime = processTime;
    }

    void setTotalTime(const double& totalTime)
    {
        if (totalTime < 0.0) this->totalTime = 0.0;
        else this->totalTime = totalTime;
    }

    void setApproved(const bool& approved)
    {
        this->approved = approved;
    }

    void setName(const string& name)
    {
        this->name = name;
    }

    string getTransaction() const
    {
        return transactionCode;
    }

    string getMOP() const
    {
        return mopCode;
    }

    string getState() const
    {
        return state;
    }

    double getStartTime() const
    {
        return startTime;
    }

    double getProcessTime() const
    {
        return processTime;
    }

    double getTotalTime() const
    {
        return totalTime;
    }

    bool getApproved() const
    {
        return approved;
    }

    string getName() const
    {
        return name;
    }

    bool operator> (const Event& other) const 
    {
        string temp = "A S L R CC D";
        if (this->startTime < other.startTime) return true;
        else if (this->startTime > other.startTime) return false;
        else 
        {
            int state1 = (int)temp.find(this->state);
            int state2 = (int)temp.find(other.state);
            if (state1 < state2) return true;
            else return false;
        }

        return false;
    }

    bool operator< (const Event& other) const
    {
        string temp = "A S L R CC D";
        if (this->startTime > other.startTime) return true;
        else if (this->startTime < other.startTime) return false;
        else 
        {
            int state1 = (int)temp.find(this->state);
            int state2 = (int)temp.find(other.state);
            if (state1 > state2) return true;
            else return false;
        }

        return false;
    }

    bool operator== (const Event& other) const
    {
        if (this->startTime == other.startTime && this->state == other.state && this->name == other.name)
        {
            return true;
        }

        return false;
    }
};

#endif