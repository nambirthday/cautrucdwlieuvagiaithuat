#include <iostream>
#include <string>
using namespace std;

class Class {
public:
    int id;
    string name;
    string teacher;
    int student_count;
    int good_students;
    int average_students;
    int fair_students;
    Class* next;

    Class(int id, string name, string teacher, int student_count, int good_students, int average_students, int fair_students) {
        this->id = id;
        this->name = name;
        this->teacher = teacher;
        this->student_count = student_count;
        this->good_students = good_students;
        this->average_students = average_students;
        this->fair_students = fair_students;
        this->next = NULL;
    }
};

class ClassLinkedList {
private:
    Class* head;

public:
    ClassLinkedList() {
        head = NULL;
    }

    void add_to_head(int id, string name, string teacher, int student_count, int good_students, int average_students, int fair_students) {
        Class* newClass = new Class(id, name, teacher, student_count, good_students, average_students, fair_students);
        newClass->next = head;
        head = newClass;
    }

    void add_to_tail(int id, string name, string teacher, int student_count, int good_students, int average_students, int fair_students) {
        Class* newClass = new Class(id, name, teacher, student_count, good_students, average_students, fair_students);
        if (head == NULL) {
            head = newClass;
        } else {
            Class* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newClass;
        }
    }

    bool remove_by_id(int id) {
        if (head == NULL) {
            return false;
        }

        if (head->id == id) {
            Class* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Class* current = head;
        while (current->next != NULL) {
            if (current->next->id == id) {
                Class* temp = current->next;
                current->next = temp->next;
                delete temp;
                return true;
            }
            current = current->next;
        }

        return false;
    }

    bool remove_by_name(string name) {
        if (head == NULL) {
            return false;
        }

        if (head->name == name) {
            Class* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Class* current = head;
        while (current->next != NULL) {
            if (current->next->name == name) {
                Class* temp = current->next;
                current->next = temp->next;
                delete temp;
                return true;
            }
            current = current->next;
        }

        return false;
    }

    Class* search_by_id(int id) {
        Class* current = head;
        while (current != NULL) {
            if (current->id == id) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    Class* search_by_name(string name) {
        Class* current = head;
        while (current != NULL) {
            if (current->name == name) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    void display_classes() {
        Class* current = head;
        while (current != NULL) {
            cout << "Ma lop: " << current->id << ", Ten lop: " << current->name << ", Giao vien chu nhiem: " << current->teacher
                 << ", So hoc sinh: " << current->student_count << ", Hoc sinh gioi: " << current->good_students
                 << ", Hoc sinh kha: " << current->average_students << ", Hoc sinh trung binh: " << current->fair_students << endl;
            current = current->next;
        }
    }

    void delete_all_classes() {
        while (head != NULL) {
            Class* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~ClassLinkedList() {
        delete_all_classes();
    }

    int count_classes_with_more_than_50_students() {
        int count = 0;
        Class* current = head;
        while (current != NULL) {
            if (current->student_count > 50) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    int count_classes_with_less_than_50_students() {
        int count = 0;
        Class* current = head;
        while (current != NULL) {
            if (current->student_count < 50) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    void sort_classes_by_student_count_ascending() {
        if (head == NULL || head->next == NULL) {
            return; // No need to sort
        }

        Class* current = head;
        Class* index = NULL;
        int temp_id, temp_student_count;
        string temp_name, temp_teacher;
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->student_count > index->student_count) {
                    temp_id = current->id;
                    temp_name = current->name;
                    temp_teacher = current->teacher;
                    temp_student_count = current->student_count;
                    current->id = index->id;
                    current->name = index->name;
                    current->teacher = index->teacher;
                    current->student_count = index->student_count;
                    index->id = temp_id;
                    index->name = temp_name;
                    index->teacher = temp_teacher;
                    index->student_count = temp_student_count;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    void sort_classes_by_student_count_descending() {
        if (head == NULL || head->next == NULL) {
            return; // No need to sort
        }

        Class* current = head;
        Class* index = NULL;
        int temp_id, temp_student_count;
        string temp_name, temp_teacher;
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->student_count < index->student_count) {
                    temp_id = current->id;
                    temp_name = current->name;
                    temp_teacher = current->teacher;
                    temp_student_count = current->student_count;
                    current->id = index->id;
                    current->name = index->name;
                    current->teacher = index->teacher;
                    current->student_count = index->student_count;
                    index->id = temp_id;
                    index->name = temp_name;
                    index->teacher = temp_teacher;
                    index->student_count = temp_student_count;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    int count_classes_with_more_than_5_good_students() {
        int count = 0;
        Class* current = head;
        while (current != NULL) {
            if (current->good_students > 5) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    int count_classes_with_less_than_or_equal_to_5_good_students() {
        int count = 0;
        Class* current = head;
        while (current != NULL) {
            if (current->good_students <= 5) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    int count_classes_with_more_than_20_average_students() {
        int count = 0;
        Class* current = head;
        while (current != NULL) {
            if (current->average_students > 20) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    int count_classes_with_less_than_or_equal_to_20_average_students() {
        int count = 0;
        Class* current = head;
        while (current != NULL) {
            if (current->average_students <= 20) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    int count_classes_with_more_than_10_fair_students() {
        int count = 0;
        Class* current = head;
        while (current != NULL) {
            if (current->fair_students > 10) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    int count_classes_with_less_than_or_equal_to_10_fair_students() {
        int count = 0;
        Class* current = head;
        while (current != NULL) {
            if (current->fair_students <= 10) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    Class* search_by_teacher(string teacher) {
        Class* current = head;
        while (current != NULL) {
            if (current->teacher == teacher) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    void sort_classes_by_average_student_count_ascending() {
        if (head == NULL || head->next == NULL) {
            return; // No need to sort
        }

        Class* current = head;
        Class* index = NULL;
        int temp_id, temp_average_students;
        string temp_name, temp_teacher;
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->average_students > index->average_students) {
                    temp_id = current->id;
                    temp_name = current->name;
                    temp_teacher = current->teacher;
                    temp_average_students = current->average_students;
                    current->id = index->id;
                    current->name = index->name;
                    current->teacher = index->teacher;
                    current->average_students = index->average_students;
                    index->id = temp_id;
                    index->name = temp_name;
                    index->teacher = temp_teacher;
                    index->average_students = temp_average_students;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    void sort_classes_by_average_student_count_descending() {
        if (head == NULL || head->next == NULL) {
            return; // No need to sort
        }

        Class* current = head;
        Class* index = NULL;
        int temp_id, temp_average_students;
        string temp_name, temp_teacher;
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->average_students < index->average_students) {
                    temp_id = current->id;
                    temp_name = current->name;
                    temp_teacher = current->teacher;
                    temp_average_students = current->average_students;
                    current->id = index->id;
                    current->name = index->name;
                    current->teacher = index->teacher;
                    current->average_students = index->average_students;
                    index->id = temp_id;
                    index->name = temp_name;
                    index->teacher = temp_teacher;
                    index->average_students = temp_average_students;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    int count_total_number_of_classes() {
        int count = 0;
        Class* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    Class* find_class_with_maximum_students() {
        if (head == NULL) {
            return NULL;
        }

        Class* maxClass = head;
        Class* current = head->next;
        while (current != NULL) {
            if (current->student_count > maxClass->student_count) {
                maxClass = current;
            }
            current = current->next;
        }
        return maxClass;
    }

    Class* find_class_with_minimum_students() {
        if (head == NULL) {
            return NULL;
        }

        Class* minClass = head;
        Class* current = head->next;
        while (current != NULL) {
            if (current->student_count < minClass->student_count) {
                minClass = current;
            }
            current = current->next;
        }
        return minClass;
    }
};

int main() {
    ClassLinkedList classes;
    
	classes.add_to_tail(1, "CNTT17_01", "Co Hang", 45, 12, 20, 13);
    classes.add_to_tail(2, "CNTT17_02", "Co Trang", 55, 15, 25, 15);
    classes.add_to_tail(3, "CNTT17_03", "Thay Phong", 40, 10, 18, 12);
    classes.add_to_tail(4, "CNTT17_04", "Thay Hong", 60, 18, 30, 20);
    
    int choice;
    do {
        cout << "\n==============================\n";
        cout << "CHUONG TRINH QUAN LY LOP HOC\n";
        cout << "==============================\n";
        cout << "1. Hien thi danh sach lop hoc\n";
        cout << "2. Them lop hoc vao dau danh sach\n";
        cout << "3. Them lop hoc vao cuoi danh sach\n";
        cout << "4. Xoa lop hoc theo Ma lop\n";
        cout << "5. Xoa lop hoc theo Ten lop\n";
        cout << "6. Tim kiem lop hoc theo Ma lop\n";
        cout << "7. Tim kiem lop hoc theo Ten lop\n";
        cout << "8. Cap nhat thong tin lop hoc\n";
        cout << "9. Dem so lop hoc co so hoc sinh lon hon 50\n";
        cout << "10. Dem so lop hoc co so hoc sinh nho hon hoac bang 50\n";
        cout << "11. Sap xep cac lop hoc theo so hoc sinh tang dan\n";
        cout << "12. Sap xep cac lop hoc theo so hoc sinh giam dan\n";
        cout << "13. Dem so lop hoc co so hoc sinh gioi lon hon 5\n";
        cout << "14. Dem so lop hoc co so hoc sinh gioi nho hon hoac bang 5\n";
        cout << "15. Dem so lop hoc co so hoc sinh kha lon hon 20\n";
        cout << "16. Dem so lop hoc co so hoc sinh kha nho hon hoac bang 20\n";
        cout << "17. Dem so lop hoc co so hoc sinh trung binh lon hon 10\n";
        cout << "18. Dem so lop hoc co so hoc sinh trung binh nho hon hoac bang 10\n";
        cout << "19. Tim kiem lop hoc theo ten giao vien chu nhiem\n";
        cout << "20. Sap xep cac lop hoc theo so hoc sinh kha tang dan\n";
        cout << "21. Sap xep cac lop hoc theo so hoc sinh kha giam dan\n";
        cout << "22. Dem tong so lop hoc\n";
        cout << "23. Tim lop hoc co so hoc sinh nhieu nhat\n";
        cout << "24. Tim lop hoc co so hoc sinh it nhat\n";
        cout << "25. Thoat chuong trinh\n";
        cout << "==============================\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nDanh sach cac lop hoc:\n";
                classes.display_classes();
                break;
            }
            case 2: {
                int id, student_count, good_students, average_students, fair_students;
                string name, teacher;
                cout << "\nNhap thong tin lop hoc:\n";
                cout << "Ma lop: "; cin >> id;
                cout << "Ten lop: "; cin.ignore(); getline(cin, name);
                cout << "Giao vien chu nhiem: "; getline(cin, teacher);
                cout << "So hoc sinh: "; cin >> student_count;
                cout << "Hoc sinh gioi: "; cin >> good_students;
                cout << "Hoc sinh kha: "; cin >> average_students;
                cout << "Hoc sinh trung binh: "; cin >> fair_students;
                classes.add_to_head(id, name, teacher, student_count, good_students, average_students, fair_students);
                cout << "Them lop hoc vao dau danh sach thanh cong.\n";
                break;
            }
            case 3: {
                int id, student_count, good_students, average_students, fair_students;
                string name, teacher;
                cout << "\nNhap thong tin lop hoc:\n";
                cout << "Ma lop: "; cin >> id;
                cout << "Ten lop: "; cin.ignore(); getline(cin, name);
                cout << "Giao vien chu nhiem: "; getline(cin, teacher);
                cout << "So hoc sinh: "; cin >> student_count;
                cout << "Hoc sinh gioi: "; cin >> good_students;
                cout << "Hoc sinh kha: "; cin >> average_students;
                cout << "Hoc sinh trung binh: "; cin >> fair_students;
                classes.add_to_tail(id, name, teacher, student_count, good_students, average_students, fair_students);
                cout << "Them lop hoc vao cuoi danh sach thanh cong.\n";
                break;
            }
            case 4: {
                int id;
                cout << "\nNhap Ma lop can xoa: ";
                cin >> id;
                if (classes.remove_by_id(id)) {
                    cout << "Xoa lop hoc thanh cong.\n";
                } else {
                    cout << "Khong tim thay lop hoc co Ma lop " << id << ".\n";
                }
                break;
            }
            case 5: {
                string name;
                cout << "\nNhap Ten lop can xoa: ";
                cin.ignore(); getline(cin, name);
                if (classes.remove_by_name(name)) {
                    cout << "Xoa lop hoc thanh cong.\n";
                } else {
                    cout << "Khong tim thay lop hoc co Ten lop \"" << name << "\".\n";
                }
                break;
            }
            case 6: {
                int id;
                cout << "\nNhap Ma lop can tim kiem: ";
                cin >> id;
                Class* found = classes.search_by_id(id);
                if (found) {
                    cout << "Tim thay lop hoc:\n";
                    cout << "Ma lop: " << found->id << ", Ten lop: " << found->name << ", Giao vien chu nhiem: " << found->teacher
                         << ", So hoc sinh: " << found->student_count << ", Hoc sinh gioi: " << found->good_students
                         << ", Hoc sinh kha: " << found->average_students << ", Hoc sinh trung binh: " << found->fair_students << endl;
                } else {
                    cout << "Khong tim thay lop hoc co Ma lop " << id << ".\n";
                }
                break;
            }
            case 7: {
                string name;
                cout << "\nNhap Ten lop can tim kiem: ";
                cin.ignore(); getline(cin, name);
                Class* found = classes.search_by_name(name);
                if (found) {
                    cout << "Tim thay lop hoc:\n";
                    cout << "Ma lop: " << found->id << ", Ten lop: " << found->name << ", Giao vien chu nhiem: " << found->teacher
                         << ", So hoc sinh: " << found->student_count << ", Hoc sinh gioi: " << found->good_students
                         << ", Hoc sinh kha: " << found->average_students << ", Hoc sinh trung binh: " << found->fair_students << endl;
                } else {
                    cout << "Khong tim thay lop hoc co Ten lop \"" << name << "\".\n";
                }
                break;
            }
            case 8: {
                // B? sung ph?n c?p nh?t thông tin l?p h?c n?u c?n
                break;
            }
            case 9: {
                cout << "\nSo lop hoc co so hoc sinh lon hon 50: " << classes.count_classes_with_more_than_50_students() << endl;
                break;
            }
            case 10: {
                cout << "\nSo lop hoc co so hoc sinh nho hon hoac bang 50: " << classes.count_classes_with_less_than_50_students() << endl;
                break;
            }
            case 11: {
                classes.sort_classes_by_student_count_ascending();
                cout << "\nDa sap xep cac lop hoc theo so hoc sinh tang dan.\n";
                break;
            }
            case 12: {
                classes.sort_classes_by_student_count_descending();
                cout << "\nDa sap xep cac lop hoc theo so hoc sinh giam dan.\n";
                break;
            }
            case 13: {
                cout << "\nSo lop hoc co so hoc sinh gioi lon hon 5: " << classes.count_classes_with_more_than_5_good_students() << endl;
                break;
            }
            case 14: {
                cout << "\nSo lop hoc co so hoc sinh gioi nho hon hoac bang 5: " << classes.count_classes_with_less_than_or_equal_to_5_good_students() << endl;
                break;
            }
            case 15: {
                cout << "\nSo lop hoc co so hoc sinh kha lon hon 20: " << classes.count_classes_with_more_than_20_average_students() << endl;
                break;
            }
            case 16: {
                cout << "\nSo lop hoc co so hoc sinh kha nho hon hoac bang 20: " << classes.count_classes_with_less_than_or_equal_to_20_average_students() << endl;
                break;
            }
            case 17: {
                cout << "\nSo lop hoc co so hoc sinh trung binh lon hon 10: " << classes.count_classes_with_more_than_10_fair_students() << endl;
                break;
            }
            case 18: {
                cout << "\nSo lop hoc co so hoc sinh trung binh nho hon hoac bang 10: " << classes.count_classes_with_less_than_or_equal_to_10_fair_students() << endl;
                break;
            }
            case 19: {
                string teacher;
                cout << "\nNhap ten giao vien chu nhiem can tim kiem: ";
                cin.ignore(); getline(cin, teacher);
                Class* found = classes.search_by_teacher(teacher);
                if (found) {
                    cout << "Tim thay lop hoc:\n";
                    cout << "Ma lop: " << found->id << ", Ten lop: " << found->name << ", Giao vien chu nhiem: " << found->teacher
                         << ", So hoc sinh: " << found->student_count << ", Hoc sinh gioi: " << found->good_students
                         << ", Hoc sinh kha: " << found->average_students << ", Hoc sinh trung binh: " << found->fair_students << endl;
                } else {
                    cout << "Khong tim thay lop hoc co giao vien chu nhiem \"" << teacher << "\".\n";
                }
                break;
            }
            case 20: {
                classes.sort_classes_by_average_student_count_ascending();
                cout << "\nDa sap xep cac lop hoc theo so hoc sinh kha tang dan.\n";
                break;
            }
            case 21: {
                classes.sort_classes_by_average_student_count_descending();
                cout << "\nDa sap xep cac lop hoc theo so hoc sinh kha giam dan.\n";
                break;
            }
            case 22: {
                cout << "\nTong so lop hoc: " << classes.count_total_number_of_classes() << endl;
                break;
            }
            case 23: {
                Class* maxClass = classes.find_class_with_maximum_students();
                if (maxClass) {
                    cout << "Lop hoc co so hoc sinh nhieu nhat:\n";
                    cout << "Ma lop: " << maxClass->id << ", Ten lop: " << maxClass->name << ", Giao vien chu nhiem: " << maxClass->teacher
                         << ", So hoc sinh: " << maxClass->student_count << ", Hoc sinh gioi: " << maxClass->good_students
                         << ", Hoc sinh kha: " << maxClass->average_students << ", Hoc sinh trung binh: " << maxClass->fair_students << endl;
                } else {
                    cout << "Khong co lop hoc nao trong danh sach.\n";
                }
                break;
            }
            case 24: {
                Class* minClass = classes.find_class_with_minimum_students();
                if (minClass) {
                    cout << "Lop hoc co so hoc sinh it nhat:\n";
                    cout << "Ma lop: " << minClass->id << ", Ten lop: " << minClass->name << ", Giao vien chu nhiem: " << minClass->teacher
                         << ", So hoc sinh: " << minClass->student_count << ", Hoc sinh gioi: " << minClass->good_students
                         << ", Hoc sinh kha: " << minClass->average_students << ", Hoc sinh trung binh: " << minClass->fair_students << endl;
                } else {
                    cout << "Khong co lop hoc nao trong danh sach.\n";
                }
                break;
            }
            case 25: {
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;
            }
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }

    } while (choice != 25);

    return 0;
}

