#include <wsjcpp_resources_manager.h>

class RES_html_images_points_svg : public WsjcppResourceFile { 
    public:
        virtual const std::string &getFilename();
        virtual const int getBufferSize();
        virtual const char *getBuffer();
};