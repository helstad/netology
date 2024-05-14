#include "Observer.h"

int main() {
    Observable observable;
    WarningObserver warningObserver;
    ErrorObserver errorObserver("errors.log");
    FatalErrorObserver fatalErrorObserver("fatal_errors.log");

    observable.addObserver(&warningObserver);
    observable.addObserver(&errorObserver);
    observable.addObserver(&fatalErrorObserver);

    observable.warning("This is a warning message");
    observable.error("This is an error message");
    observable.fatalError("This is a fatal error message");

    observable.removeObserver(&warningObserver);
    observable.removeObserver(&errorObserver);
    observable.removeObserver(&fatalErrorObserver);

	return 0;
}