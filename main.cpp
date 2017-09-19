#include <phpcpp.h>
#include <iostream>
#include <vector>
#include "sort.h"

Php::Value quick_sort(Php::Parameters &params)
{
    std::vector<int> arr = params[0];

    quickSort(arr);

    return arr;
}

Php::Value heap_sort(Php::Parameters &params)
{
    std::vector<int> arr = params[0];

    heapSort(arr);

    return arr;
}

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {
    
    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module() 
    {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("sort", "1.0");
        
        // @todo    add your own functions, classes, namespaces to the extension
        extension.add<quick_sort>("quick_sort", {
            Php::ByVal("a", Php::Type::Array)
        });
        
        extension.add<heap_sort>("heap_sort", {
            Php::ByVal("a", Php::Type::Array)
        });

        // return the extension
        return extension;
    }
}
