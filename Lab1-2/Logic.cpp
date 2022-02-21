#include <string>
#include <vector>
#include "Header.h"

void calculateExpirationDates(std::vector<Medicine*>& m, std::vector<OpenedMedicine*>& m2) {
    for (int i = 0; i < m.size(); i++) {
        int found = -1;
        for (int j = 0; j < m2.size(); j++) {
            if (m[i]->name == m2[j]->name) found = j;
        }

        if (found > -1) {
            m2[found]->endTimestamp = m2[found]->openTimestamp + m[i]->minutes + m[i]->hours * 60;
        }
    }
}