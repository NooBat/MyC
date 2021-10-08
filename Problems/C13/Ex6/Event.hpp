#ifndef _EVENT
#define _EVENT

class Event
{
private:
    char state;
    int startTime;
    int processTime;
public:
    Event()
    {
        startTime = 0;
        processTime = 0;
    }

    Event(const char& state, const int& startTime, const int& processTime = 0)
    {
        this->setState(state);
        this->startTime = startTime;
        this->processTime = processTime;
    }

    Event(const Event& other)
    {
        this->setState(other.state);
        this->startTime = other.startTime;
        this->processTime = other.processTime;
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

    int getStartTime() const
    {
        return startTime;
    }

    int getProcessTime() const
    {
        return processTime;
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