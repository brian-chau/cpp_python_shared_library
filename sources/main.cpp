#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>
#include <string>
#include <sys/stat.h>

#include "types.h"

extern "C" {
    void count_PU_DO_Locations(const char* filename, int * pu_count, int * do_count ){
        std::string   line;
        std::ifstream file(filename);

        if (file.is_open()) {
            struct stat st;
            int         m_file_size;

            if (stat(filename, &st) != 0) {
                m_file_size = 0;
            }
            m_file_size = st.st_size;
            int recs    = m_file_size / RECORD_SIZE;

            // Start counting records
            *pu_count = 0;
            *do_count = 0;
            Data data;
            for (int i=0; i < recs; i++) {
                memset(&data, 0, RECORD_SIZE);
                file.read((char*)data.buffer, RECORD_SIZE);
                if (data.record.payment_type == 3) {
                    if (data.record.PULocationID == 170) {
                        (*pu_count)++;
                    } else if (data.record.DOLocationID == 170) {
                        (*do_count)++;
                    }
                }
            }

            file.close();
            return;
        }
        std::cout << "Cannot open file" << std::endl;
        return;
    }
}
