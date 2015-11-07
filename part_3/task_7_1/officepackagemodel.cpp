#include <officepackagemodel.h>
#include <officepackage.h>

void OfficePackageModel::init(OfficePackage packages[], int length) {
    for(int i = 0; i < length; i++) {
        this->data.push_back(packages[i]);
    }
}

QVector<OfficePackage>* OfficePackageModel::getData() {
    return &this->data;
}
