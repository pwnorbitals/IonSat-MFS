#ifndef EVENT_H_INC
#define EVENT_H_INC

namespace FFS {
    typedef unsigned int MessageType;

    struct EventDataStruct {
        unsigned int msg_class;
        unsigned int msg_type;
        char sender_name[64];
        char data[512];
    };

    struct EventStruct {
        unsigned short start;
        unsigned int length;
        char md5[32];
        EventDataStruct packet;
    };

    class Event {
        protected:
            EventDataStruct data;

        public:
            Event();
            ~Event();

            EventStruct getData();
            static void parseBuffer(char* buf);
            char* serialize();
    };
}

#endif