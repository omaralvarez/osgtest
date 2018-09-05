#include <iostream>
#include <osgViewer/Viewer>

int main(int argc, char** argv)
{

    osg::ArgumentParser arguments(&argc, argv);

    osgViewer::Viewer viewer(arguments);

    osg::GraphicsContext::WindowingSystemInterface* wsi = osg::GraphicsContext::getWindowingSystemInterface();
    if ( !wsi ) 
    {
        std::cout << "ERROR. Could not access the Windowing System Interface" << std::endl;
        throw -1;
    }
    
    std::cout << wsi->getNumScreens() << " screen(s) detected" << std::endl;
    for ( unsigned int screen=0 ; screen < wsi->getNumScreens(); screen++ ) 
    {
        osg::GraphicsContext::ScreenIdentifier screen_id(screen);
        osg::GraphicsContext::ScreenSettings screen_settings;
        wsi->getScreenSettings( screen_id, screen_settings );
        std::cout << "  Screen #" << screen << " : "
                  << screen_settings.width << "x" << screen_settings.height << " "
                  << screen_settings.refreshRate << "Hz "
                  << screen_settings.colorDepth << " bit" << std::endl;
    }

    viewer.run();

    return 0;

}