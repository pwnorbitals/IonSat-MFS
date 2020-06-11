#ifndef MODE_H_INC
#define MODE_H_INC

namespace FFS {
    class Mode {
        protected:
            std::string name;

        public:
            Mode();
            virtual ~Mode();
    };
}

#endif