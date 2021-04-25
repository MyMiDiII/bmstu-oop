#include "base_excepton.h"

using namespace std;

BaseExcepton::BaseExcepton(
        const str &time, const str &fileName,
        const uint line, const str &className,
        const str &methodName, const str &info = "Something went wrong!")
{
    errInfo = "\nTime:   " + time +
              "\nFile:   " + fileName +
              "\nLine:   " + to_string(line) +
              "\nClass:  " + className +
              "\nMethod: " + methodName +
              "\nInfo:   " + info + "\n";
}

const char *BaseExcepton::what() const noexcept
{
    return errInfo.c_str();
}
