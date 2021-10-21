#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <boost/exception_ptr.hpp>
#include <boost/lexical_cast.hpp>
class boost_exception_processor {
public:
    explicit boost_exception_processor(const boost::exception_ptr &ex) : exception_(ex) {
    }
    void operator () () {
        try {
            boost::rethrow_exception(exception_);
        }
        catch (const boost::bad_lexical_cast &) {
            std::cerr << "lexical cast exception detected!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (...) {
            std::cerr << "can not handle such exception:";
            std::cerr << boost::current_exception_diagnostic_information() << std::endl;
        }
    }
private:
    boost::exception_ptr exception_;
};