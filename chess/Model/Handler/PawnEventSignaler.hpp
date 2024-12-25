#ifndef PAWNEVENTSIGNALER
#define PAWNEVENTSIGNALER

struct PawnEventSignaler {
    public:
    static void activateState();
    static void deactivateState();
    static bool isEventActive();
    private:
    static bool _eventState;
};
#endif //PAWNEVENTSIGNALER