#ifndef EVENT_H_INC
#define EVENT_H_INC

enum eventTypes; // Must be specified by user
typedef enum eventType eventType;

namespace FFS {
    typedef unsigned int MessageType;

    template<typename T>
    struct EventDataStruct {
        eventType type;
        char sender_name[64];
        T data;
    };

    template<typename T>
    struct EventType {
        std::string name;


        EventType() { 
            
        };
    }

    struct EventStruct {
        unsigned short start;
        unsigned int length;
        char md5[32];
        EventDataStruct packet;
    };

    template<typename T>
    class Event {
        protected:
            EventDataStruct<T> data;

        public:
            Event(eventType type,  data);
            virtual ~Event();

            static char startMarker[2];

            EventDataStruct getData();
            static void parseBuffer(char* buf);
            char* serialize();
    };
}

#endif