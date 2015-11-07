#ifndef OFFICEPACKAGE
#define OFFICEPACKAGE

#endif // OFFICEPACKAGE

#include <QString>

class OfficePackage {
public:
    OfficePackage();
    OfficePackage(QString name, QString company, QString count, QString price);
    QString name, company, count, price;
};
