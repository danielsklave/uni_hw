class SimboluSteks
{
private:
    char *steks;
    int skaits;

public:
    SimboluSteks();
    ~SimboluSteks();
    void push(char);
    bool pop(char &);
    int count();
    char top();
    bool isEmpty();
    bool isFull();
};
