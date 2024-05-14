#include "LogChain.h"
#include <iostream>

int main() {
    FatalErrorHandler fatalErrorHandler;
    ErrorHandler errorHandler("errors.log");
    WarningHandler warningHandler;
    UnknownMessageHandler unknownMessageHandler;

    unknownMessageHandler.setNextHandler(&warningHandler);
    warningHandler.setNextHandler(&errorHandler);
    errorHandler.setNextHandler(&fatalErrorHandler);

    LogMessage warningMessage(MessageType::Warning, "This is a warning");
    LogMessage errorMessage(MessageType::Error, "This is an error");
    LogMessage fatalErrorMessage(MessageType::FatalError, "This is a fatal error");
    LogMessage unknownMessage(MessageType::Unknown, "This is an unknown message");

    try {
        unknownMessageHandler.handle(warningMessage);
        unknownMessageHandler.handle(errorMessage);
        unknownMessageHandler.handle(fatalErrorMessage);
        unknownMessageHandler.handle(unknownMessage);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
