#include <officepackage.h>
#include <QString>

OfficePackage::OfficePackage() {

}

OfficePackage::OfficePackage(QString name, QString company, QString count, QString price) {
    this->name = name;
    this->company = company;
    this->count = count;
    this->price = price;
}
