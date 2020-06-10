#ifndef EVENT_H_INC
#define EVENT_H_INC

namespace FFS {
    typedef unsigned int MessageType;

    struct EventPacketStruct {
        unsigned int msg_class;
        unsigned int msg_type;
        char sender_name[64];
        char data[512];
    };

    struct EventStruct {
        unsigned short start;
        unsigned int length;
        char md5[32];
        EventPacketStruct packet;
    };

    class Event {
        protected:
            EventStruct data;

        public:
            Event() {};
            ~Event() {};

            EventStruct getData() { return data; };

            static void parseBuffer(char* buf) {

                FFS::emit();
            }

            char* serialize() {
                
            }
    };
}

#endif