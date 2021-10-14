#ifndef _EVENT
#define _EVENT

class Event
{
private:
    char state;
    double startTime;
    double processTime;
    int fromLine;
    int fromTeller;
public:
    Event()
    {
        startTime = 0.0;
        processTime = 0.0;
    }

    Event(const char& state, const double& startTime, const double& processTime = 0, const int& fromLine = -1, const int& fromTeller = -1)
    {
        this->setState(state);
        this->startTime = startTime;
        this->processTime = processTime;
        this->fromLine = fromLine;
        this->fromTeller = fromTeller;
    }

    Event(const Event& other)
    {
        this->setState(other.state);
        this->startTime = other.startTime;
        this->processTime = other.processTime;
        this->fromLine = other.fromLine;
        this->fromTeller = other.fromTeller;
    }

    bool setState(const char& state)
    {
        char temp = state;

        toupper(temp);

        this->state = temp;

        return true;
    }

    char getState() const
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

    int getFromLine() const
    {
        return fromLine;
    }

    int getFromTeller() const
    {
        return fromTeller;
    }

    bool operator> (const Event& other) const
    {
        bool result;
        if (this->startTime > other.startTime)
        {
            result = true;       
        }
        else if (this->startTime < other.startTime) result = false;
        else 
        {
            if (this->state < other.state) result = true;
            else result = false;
        }

        return result;
    }

    bool operator< (const Event& other) const
    {
        bool result;
        if (this->startTime < other.startTime)
        {
            result = true;       
        }
        else if (this->startTime > other.startTime) result = false;
        else 
        {
            if (this->state > other.state) result = true;
            else result = false;
        }

        return result;

        return result;
    }

    bool operator== (const Event& other) const
    {

        if (this->startTime == other.startTime
            && this->state == other.state) return true;

        return false;
    }
};
#endif