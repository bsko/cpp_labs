#ifndef OFFICEPACKAGEMODEL
#define OFFICEPACKAGEMODEL

#endif // OFFICEPACKAGEMODEL

#include <QVector>

class OfficePackage;

class OfficePackageModel {
public:
    void init(OfficePackage packages[], int length);
    QVector<OfficePackage>* getData();
private:
    QVector<OfficePackage> data;
};
