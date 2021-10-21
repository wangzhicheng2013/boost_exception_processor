#include "boost_exception_processor.hpp"
void test_fun1() {
    try {
        boost::lexical_cast<int>("hello boost!");
    }
    catch (...) {
        auto boost_ex = boost_exception_processor(boost::current_exception());
        boost_ex();
    }
}
void test_fun2() {
    try {
        BOOST_THROW_EXCEPTION(std::logic_error("some fatal logic error!"));
    }
    catch (...) {
        auto boost_ex = boost_exception_processor(boost::current_exception());
        boost_ex();
    }
}
int main() {
    test_fun1();
    test_fun2();

    return 0;
}