void logger(HouseKeepingEvent const& event) {
    std::cout << event.message << " at " << event.timestamp << " on " << event.meta << std::endl;
}