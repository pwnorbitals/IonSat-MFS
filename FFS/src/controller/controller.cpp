#include "FFS.h"

namespace FFS {
    void addEventType(unsigned int identifier, std::string name) {
        FFS::Controller().addEventType(identifier, name);
    };


    void Controller::addEventType(unsigned int identifier, std::string name) {
        
    };

    void addMode() {

    };

    void Controller::addMode() {

    };

    void emit(FFS::Event evt) {

    };

    void Controller::emit(FFS::Event evt) {

    };

    void start() {

    };

    void Controller::start() {

    };

    Controller::Controller() {

    };

    Controller::~Controller() {

    };

    Controller& Controller::operator()() {
        return instance;
    };

}