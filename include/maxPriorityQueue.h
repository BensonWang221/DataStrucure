template <class T>
class maxPriorityQueue
{
public:
    virtual ~maxPriorityQueue() {}

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual const T &top() const = 0;

    virtual void push(const T &) = 0;

    virtual void pop() = 0;
};