#include <iostream>
#include <queue>
#include <vector>

class arr_dep_event
{
private:

    char event_type;//A for arrival and D for departure

    int time;
    int transaction_length;//only applies for arrival

public:
    arr_dep_event();
    arr_dep_event(int iTime, int trans_len);
    arr_dep_event(int iTime, int trans_len, char ev_type);

    int getTime() const;
    int getTransactionLength() const;
    char getEventType() const;
};

arr_dep_event::arr_dep_event()
{
    event_type = ' ';
    time = 0;
    transaction_length = 0;

}

arr_dep_event::arr_dep_event(int iTime, int trans_len)
{
    event_type = 'A';
    time = iTime;
    transaction_length = trans_len;

}

arr_dep_event::arr_dep_event(int iTime, int trans_len, char ev_type)
{
    event_type = ev_type;
    time = iTime;
    transaction_length = trans_len;

}

int arr_dep_event::getTime() const
{
    return time;
}

int arr_dep_event::getTransactionLength() const
{
    return transaction_length;
}

char arr_dep_event::getEventType() const
{
    return event_type;
}

template <typename Comparable>
void AddToQueue(std::priority_queue<arr_dep_event, std::vector<arr_dep_event>, Comparable>& pq, const arr_dep_event& event)
{
    pq.push(event);
    std::cout << "pq.size() = " << pq.size() << std::endl;
}

/**
 * @brief Print the contents of a priority queue
 * @tparam Comparable the type of the comparator used by the priority queue
 * @param pq a priority queue intentionally passed by value so that the actual argument remains unchanged
 */
template <typename Comparable>
void PrintQueue(std::priority_queue<arr_dep_event, std::vector<arr_dep_event>, Comparable> pq)
{
    while(!pq.empty())
    {
        std::cout << pq.top().getEventType() << pq.top().getTime() << "\n";
        pq.pop();
    }
}

int main()
{
    auto cmp = [](auto left, auto right) { return (left.getTime()) > (right.getTime()); };
    std::priority_queue<arr_dep_event, std::vector<arr_dep_event>, decltype(cmp)> eventQueue(cmp);

    arr_dep_event a1{20, 6};
    arr_dep_event a2{22, 4};
    arr_dep_event a3{28, 8};
    arr_dep_event d1{26, 0, 'D'};

    AddToQueue( eventQueue, a1 );
    AddToQueue( eventQueue, a2 );
    AddToQueue( eventQueue, a3 );
    AddToQueue( eventQueue, d1 );

    std::cout << "Before printing: eventQueue.size() = " << eventQueue.size() << std::endl;
    PrintQueue(eventQueue);
    std::cout << "After printing:  eventQueue.size() = " << eventQueue.size() << std::endl;
    return 0;
}
