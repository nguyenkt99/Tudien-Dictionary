#define COLOR_HIGH_LIGHT 24
#define COLOR_DEFAULT 112
#define COLOR_BUTTON 124
#define COLOR_HIGH_LIGHT_KEY 240
#define COLOR_MESSAGE 79
#define COLOR_BUTTON_MESSAGE 28
#define COLOR_FRAME 115
#define COLOR_DICT_ART 117

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32
#define UP 72
#define DOWN 80
#define DEL 83
#define INSERT 82
#define ESC 27
#define HOME 71
#define LEFT 75
#define RIGHT 77
#define F10 68

#define X_POS_MAIN_FRAME_BEGIN 5
#define Y_POS_MAIN_FRAME_BEGIN 10
#define MAIN_FRAME_WIDTH 25
#define MAIN_FRAME_HEIGHT 25

#define X_POS_MESSAGE_BEGIN 50
#define Y_POS_MESSAGE_BEGIN 8
#define X_POS_FRAME_MESSAGE_BEGIN 42
#define Y_POS_FRAME_MESSAGE_BEGIN 3

#define X_POS_FRAME_GUIDE_BEGIN 3
#define Y_POS_FRAME_GUIDE_BEGIN 36
#define GUIDE_FRAME_WIDTH 121
#define GUIDE_FRAME_HEIGHT 2

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

// Cac ham xu ly console ===============================================================
void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void setFullScreen() {
    system("mode con COLS=700");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

void gotoXY(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Nocursortype(bool check) {
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = check;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
// ==========================================================================================

// Cac ham xu li console ================================================================
void showDictionaryArt() {
	ifstream fileDictArt;
    fileDictArt.open("dictionaryart.txt");
    
    string temp;
    int line = 0;
    TextColor(COLOR_DICT_ART);
    while (!fileDictArt.eof()) {
        gotoXY(35, line++);
        getline(fileDictArt, temp);
        cout << temp << endl;
    }
    TextColor(COLOR_DEFAULT);
    fileDictArt.close();
}
void drawFrame(int x, int y, int width, int height) {
    char a = 201, b = 205, c = 187, d = 186, e = 200, f = 188; //Ki tu dac biet 

    gotoXY(x, y);
    cout << a; // goc tren trai
    cout << string(width - 1, b);

    gotoXY(x + width, y); // goc tren phai
    cout << c;
    for (int i = 1; i < height; i++) {
        gotoXY(x, y + i);
        cout << d;
    }

    gotoXY(x, y + height); // goc duoi trai
    cout << e;
    cout << string(width - 1, b);

    gotoXY(x + width, y + height); // goc duoi phai
    cout << f;
    for (int i = 1; i < height; i++) {
        gotoXY(x + width, y + i);
        cout << d;
    }
}

// Hien thi phim nong o khung chinh
void showHotkeysMainGuide() {
    gotoXY(X_POS_FRAME_GUIDE_BEGIN + 1, Y_POS_FRAME_GUIDE_BEGIN + 1);
    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Esc";
    TextColor(COLOR_DEFAULT);
    cout << " :Thoat chuong trinh   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Delete";
    TextColor(COLOR_DEFAULT);
    cout << " :Xoa tu   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Insert";
    TextColor(COLOR_DEFAULT);
    cout << " :Them tu   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Tab";
    TextColor(COLOR_DEFAULT);
    cout << " :Xem chi tiet va chinh sua   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Home";
    TextColor(COLOR_DEFAULT);
    cout << " :Ve dau danh sach";
}

// Hien thi phim nong o tab tu va tab loai tu
void showHotkeysWordAndWordType() {
    gotoXY(X_POS_FRAME_GUIDE_BEGIN + 1, Y_POS_FRAME_GUIDE_BEGIN + 1);
    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Esc";
    TextColor(COLOR_DEFAULT);
    cout << " :Quay lai   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Enter";
    TextColor(COLOR_DEFAULT);
    cout << " :Chinh sua/luu lai   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Tab";
    TextColor(COLOR_DEFAULT);
    cout << " :Chuyen qua phan tiep theo   ";
}

// Hien thi phim nong o tab nghia va tab vi du
void showHotkeysMeanAndExample() {
    gotoXY(X_POS_FRAME_GUIDE_BEGIN + 1, Y_POS_FRAME_GUIDE_BEGIN + 1);
    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Esc";
    TextColor(COLOR_DEFAULT);
    cout << " :Quay lai   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Enter";
    TextColor(COLOR_DEFAULT);
    cout << " :Chinh sua/luu lai   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Delete";
    TextColor(COLOR_DEFAULT);
    cout << " :Xoa   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Insert";
    TextColor(COLOR_DEFAULT);
    cout << " :Them   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Tab";
    TextColor(COLOR_DEFAULT);
    cout << " :Chuyen qua phan tiep theo   ";
}

// Hien thi phim nong o tab tu va loai tu khi them tu
void showHotkeysWordAndWordTypeIns() {
    gotoXY(X_POS_FRAME_GUIDE_BEGIN + 1, Y_POS_FRAME_GUIDE_BEGIN + 1);
    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Esc";
    TextColor(COLOR_DEFAULT);
    cout << " :Quay lai   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Enter";
    TextColor(COLOR_DEFAULT);
    cout << " :Chinh sua/luu lai   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "F10";
    TextColor(COLOR_DEFAULT);
    cout << " :Luu tu moi   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Tab";
    TextColor(COLOR_DEFAULT);
    cout << " :Chuyen qua phan tiep theo";
}

// Hien thi phim nong o tab nghia va vi du khi them tu
void showHotkeysMeanAndExampleIns() {
    gotoXY(X_POS_FRAME_GUIDE_BEGIN + 1, Y_POS_FRAME_GUIDE_BEGIN + 1);
    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Esc";
    TextColor(COLOR_DEFAULT);
    cout << " :Quay lai   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Enter";
    TextColor(COLOR_DEFAULT);
    cout << " :Chinh sua/luu lai   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Delete";
    TextColor(COLOR_DEFAULT);
    cout << " :Xoa   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Insert";
    TextColor(COLOR_DEFAULT);
    cout << " :Them   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "F10";
    TextColor(COLOR_DEFAULT);
    cout << " :Luu tu moi   ";

    TextColor(COLOR_HIGH_LIGHT_KEY);
    cout << "Tab";
    TextColor(COLOR_DEFAULT);
    cout << " :Chuyen qua phan tiep theo";
}

// Ham xoa thong diep
void deleteFrameMessage() {
    for (int i = 0; i < Y_POS_FRAME_MESSAGE_BEGIN + 1; i++) {
        gotoXY(X_POS_MESSAGE_BEGIN, Y_POS_MESSAGE_BEGIN + i);
        cout << string(56, ' ');
    }
}

void deleteHotkeysGuide() {
    gotoXY(X_POS_FRAME_GUIDE_BEGIN + 1, Y_POS_FRAME_GUIDE_BEGIN + 1);
    cout << string(GUIDE_FRAME_WIDTH - 1, ' ');
}

// Khung FindFirstWordStr, hien thi
void drawMainFrame() {
    TextColor(COLOR_FRAME);
    drawFrame(X_POS_MAIN_FRAME_BEGIN, Y_POS_MAIN_FRAME_BEGIN, MAIN_FRAME_WIDTH, MAIN_FRAME_HEIGHT); // Khung FindFirstWordStr
    drawFrame(X_POS_FRAME_GUIDE_BEGIN, Y_POS_FRAME_GUIDE_BEGIN, GUIDE_FRAME_WIDTH, GUIDE_FRAME_HEIGHT); // Khung hotkey

    // In thanh ngang info search
    gotoXY(X_POS_MAIN_FRAME_BEGIN + 1, Y_POS_MAIN_FRAME_BEGIN + 2);
    cout << string(MAIN_FRAME_WIDTH - 1, '_');

    // In thanh ngang info Word
	gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 4);
	cout << string(75, '_');
    TextColor(COLOR_DEFAULT);
}

int showMenuConfirmSave() {
    char k;
    drawFrame(X_POS_MESSAGE_BEGIN, Y_POS_MESSAGE_BEGIN, X_POS_FRAME_MESSAGE_BEGIN, Y_POS_FRAME_MESSAGE_BEGIN);

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 1);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ENTER";
    TextColor(COLOR_DEFAULT);
    cout << " de luu chinh sua!";

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 2);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ESC";
    TextColor(COLOR_DEFAULT);
    cout << " de quay lai chinh sua!";

    do {
        k = _getch();
    } while (k != ENTER && k != ESC);
    deleteFrameMessage();
    return (int) k;
}

int showMenuConfirmSaveWord() {
    char k;
    drawFrame(X_POS_MESSAGE_BEGIN, Y_POS_MESSAGE_BEGIN, X_POS_FRAME_MESSAGE_BEGIN, Y_POS_FRAME_MESSAGE_BEGIN);

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 1);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ENTER";
    TextColor(COLOR_DEFAULT);
    cout << " de luu tu can them!";

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 2);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ESC";
    TextColor(COLOR_DEFAULT);
    cout << " de quay lai!";

    do {
        k = _getch();
    } while (k != ENTER && k != ESC);
    deleteFrameMessage();
    return (int) k;
}

int showMenuConfirmNoChange() {
    char k = ' ';
    drawFrame(X_POS_MESSAGE_BEGIN, Y_POS_MESSAGE_BEGIN, X_POS_FRAME_MESSAGE_BEGIN, Y_POS_FRAME_MESSAGE_BEGIN);

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 1);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ENTER";
    TextColor(COLOR_DEFAULT);
    cout << " de huy thay doi!";

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 2);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ESC";
    TextColor(COLOR_DEFAULT);
    cout << " de tiep tuc chinh sua!";

    do {
        k = _getch();
    } while (k != ENTER && k != ESC);

    deleteFrameMessage();
    return (int) k;
}

int showMenuConfirmCancel() {
    char k = ' ';
    drawFrame(X_POS_MESSAGE_BEGIN, Y_POS_MESSAGE_BEGIN, X_POS_FRAME_MESSAGE_BEGIN, Y_POS_FRAME_MESSAGE_BEGIN);

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 1);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ENTER";
    TextColor(COLOR_DEFAULT);
    cout << " thoat. Tu se khong duoc luu!";

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 2);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ESC";
    TextColor(COLOR_DEFAULT);
    cout << " de tiep tuc!";

    do {
        k = _getch();
    } while (k != ENTER && k != ESC);

    deleteFrameMessage();
    return (int) k;
}

int showMenuConfirmDelete() {
    char k = ' ';
    drawFrame(X_POS_MESSAGE_BEGIN, Y_POS_MESSAGE_BEGIN, X_POS_FRAME_MESSAGE_BEGIN, Y_POS_FRAME_MESSAGE_BEGIN);

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 1);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ENTER";
    TextColor(COLOR_DEFAULT);
    cout << " xoa!";

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 2);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ESC";
    TextColor(COLOR_DEFAULT);
    cout << " de quay lai!";

    do {
        k = _getch();
    } while (k != ENTER && k != ESC);

    deleteFrameMessage();
    return (int) k;
}

int showMenuConfirmExit() {
    char k = '0';
    drawFrame(X_POS_MESSAGE_BEGIN, Y_POS_MESSAGE_BEGIN, X_POS_FRAME_MESSAGE_BEGIN, Y_POS_FRAME_MESSAGE_BEGIN);

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 1);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ENTER";
    TextColor(COLOR_DEFAULT);
    cout << " de thoat chuong trinh";

    gotoXY(X_POS_MESSAGE_BEGIN + 1, Y_POS_MESSAGE_BEGIN + 2);
    cout << "Nhan ";
    TextColor(COLOR_BUTTON);
    cout << "ESC";
    TextColor(COLOR_DEFAULT);
    cout << " de quay lai chuong trinh";
    do {
        k = _getch();
    } while (k != ENTER && k != ESC);

    deleteFrameMessage();
    return (int) k;
}

// Ham xoa console su dung dau cach => Khong bi lag, muot hon
void clearUseSpace(int begin, int end) {
    if (begin < end)
	    cout << string(end-begin, ' ');
}

void clearInfoWord() {
    TextColor(COLOR_DEFAULT);
    // Xoa tu tieng Anh
    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 3);
    cout << string(24, ' ');

    // Xoa loai tu
    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 6);
    cout << string(24, ' ');

    // Xoa nghia truoc khi in
    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 8);
    cout << string(3, ' ');
    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 13);
    cout << string(3, ' ');

    // Xoa cac nghia
    for (int i = 0; i < 4; i++) {
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15, Y_POS_MAIN_FRAME_BEGIN + 9 + i);
        cout << string(26, ' ');
    }
	
    // Xoa cac vd
    for (int i = 0; i < 6; i++) {
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 16 + i); // 10
        cout << string(61, ' ');
    }
}
// ==========================================================================================

// Cau truc du lieu de tai TU DIEN ==========================================================
struct Mean {
    string data;
    Mean* next;
};

struct Word {
    string tu; // Tu tieng anh
    Mean* tv; // Cac nghia tieng Viet theo cau truc danh sach lien ket don
    string loaiTu;
    string* viDu[5]; // cac vi du theo cau truc mang con tro
    Word* prev;
    Word* next;
};

struct WordList {
    Word* head = NULL;
    Word* tail = NULL;
};

int hashCode(string key) {
    return (int) key[0] - 97;
}

void addMean(Mean*& head, Mean* mean) {
    if (head == NULL) {
        head = mean;
    } else {
        Mean* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = mean;
    }
}

void addTailWord(WordList& l, Word* p) {
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        p->prev = l.tail;
        l.tail->next = p;
        l.tail = p;
    }
}

// Ham doc mot dong trong file text tra ve mot tu
Word* readLine(ifstream& FileIn) {
    Word* p = new Word;
    p->prev = NULL;
    p->next = NULL;

    Mean* head = NULL;

    getline(FileIn, p->tu, '|');
    if (p->tu.size() == 0) {
        delete p;
        return NULL;
    }
    getline(FileIn, p->loaiTu, '|');
    while (true) {
        string temp = "";
        getline(FileIn, temp, '|');
        if (temp == ".") {
            break;
        }
        else {
            Mean* x = new Mean;
            x->next = NULL;
            x->data = temp;
            addMean(head, x);
        }
    }
    p->tv = head;

    for (int i = 0; i < 5; i++) {
        string temp = "";
        getline(FileIn, temp, '|');
        if (!temp.empty()) {
            p->viDu[i] = new string;
            *(p->viDu[i]) = temp;
        } else {
            p->viDu[i] = NULL;
        }
    }
    FileIn.ignore(1); // Xuong dong tiep theo

    return p;
}

void addWordHashTable(WordList HashTable[], ifstream& FileIn) {
    if (FileIn.fail())
        return;

    while (!FileIn.eof()) {
        Word* p = readLine(FileIn);
        if (!p) return;
        int index = hashCode(p->tu);
        addTailWord(HashTable[index], p);
    }
}

void removeMean(Mean*& head, string nghia) {
    Mean* meanDel = NULL;
    Mean* p1 = head;
    Mean* p2 = head;

    while (p1 != NULL && p1->data != nghia) {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1 == NULL) {
        return;
    } else {
        meanDel = p1;
        p2->next = p1->next;
        if (meanDel == head) {
            head = head->next;
            p2 = NULL;
        }
        delete meanDel;
    }
}

// Ham giai phong bo nho
void free(WordList HashTable[]) {
    for (int i = 0; i < 26; i++) {
        if (HashTable[i].head != NULL) {
            Word* wordDel = NULL;
            Mean* meanDel = NULL;
            while (HashTable[i].head != NULL) {
                wordDel = HashTable[i].head; // chu?n b? Word head d? cu?i vòng l?p s? xóa
                // xóa các nghia
                Mean* meanHead = HashTable[i].head->tv;
                while (meanHead != NULL) {
                    meanDel = meanHead;
                    meanHead = meanHead->next;
                    delete meanDel;
                }
                // xóa các ví d?
                for (int j = 0; j < 5; j++) // vì có t?i da 5 vd
                    delete HashTable[i].head->viDu[j];
                HashTable[i].head = HashTable[i].head->next; // Word head s? là Word head->next
                delete wordDel;
            }
        }
    }
}
// ==========================================================================================

void chuanHoaNghia(string& temp) {
    while (temp[0] == ' ')
        temp.erase(temp.begin());
    if (!temp.empty()) {
        while (temp[temp.length() - 1] == ' ')
            temp.erase(temp.length() - 1, 1);
    }
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == ' ' && temp[i + 1] == ' ') {
            temp.erase(i, 1);
            i--;
        }
    }
    temp = _strlwr((char*) temp.c_str());
}

void chuanHoaViDu(string& temp) {
    while (temp[0] == ' ')
        temp.erase(temp.begin());
    if (!temp.empty()) {
        while (temp[temp.length() - 1] == ' ')
            temp.erase(temp.length() - 1, 1);
    }
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == ' ' && temp[i + 1] == ' ') {
            temp.erase(i, 1);
            i--;
        }
    }
    if (temp[0] >= 'a' && temp[0] <= 'z')
        temp[0] -= 32;
}

// Ham tim tu ben trai tu bat ki
Word* findWordLeft(WordList HashTable[], Word* curr) {
    if (curr != NULL) {
        Word* left = curr->prev;
        if (left != NULL) {
            return left;
        } else {
            int index = hashCode(curr->tu);
            if (index > 0) {
                index--;
                while (index >= 0) {
                    if (HashTable[index].tail != NULL) {
                        return HashTable[index].tail;
                    }
                    index--;
                }
            }
        }
    }
    return NULL;
}

// Ham tim tu ben phai tu bat ki
Word* findWordRight(WordList HashTable[], Word* curr) {
    if (curr != NULL) {
        Word* right = curr->next;
        if (right != NULL) {
            return right;
        } else {
            int index = hashCode(curr->tu);
            if (index < 25) {
                index++;
                while (index < 26) {
                    if (HashTable[index].head != NULL) {
                        return HashTable[index].head;
                    }
                    index++;
                }
            }

        }
    }
    return NULL;
}

// Ham tim tu cuoi khung
Word* findWordEndFrame(WordList HashTable[], Word* beginBox, string str) {
    Word* run = beginBox, *temp = NULL;
    for (int i = 0; i < (MAIN_FRAME_HEIGHT - 4) && run; i++) {
        temp = findWordRight(HashTable, run);
        if (temp && temp->tu.find(str) == 0)
            run = temp;
        else
            return run;
    }
    return run;
}

// Ham tim tu dau tien trong HashTable
void findFirstWord(WordList HashTable[], Word*& wordHome) { // Tim vi tri tu dau tien trong tu dien va gan cho wordHome
    for (int i = 0; i < 26; i++) {
        if (HashTable[i].head != NULL) {
            wordHome = HashTable[i].head;
            return;
        }
    }
    wordHome = NULL;
}

// Tim tu dau tien khi co chuoi go vao o tim kiem
Word* findFirstWordStr(WordList HashTable[], string str) {
    for (Word* k = HashTable[hashCode(str)].head; k != NULL; k = k->next)
        if (k->tu.find(str) == 0)
            return k;
    return NULL;
}

// Hien thi danh sach cac tu thoa man co trong HashTable phu hop voi do dai bang hien thi
void showWordList(WordList HashTable[], Word*& curr, Word*& wordBeginFrame, Word*& wordEndFrame) {
    int line = 0;
    for (Word* k = wordBeginFrame; k != findWordRight(HashTable, wordEndFrame); k = findWordRight(HashTable, k)) {
        gotoXY(X_POS_MAIN_FRAME_BEGIN + 1, Y_POS_MAIN_FRAME_BEGIN + 3 + line);
        if (k == curr) {
            TextColor(COLOR_HIGH_LIGHT);
            cout << k->tu;
            clearUseSpace(k->tu.length(), MAIN_FRAME_WIDTH - 1);
            TextColor(COLOR_DEFAULT);
        } else {
            cout << k->tu;
            clearUseSpace(k->tu.length(), MAIN_FRAME_WIDTH - 1);
        }
        line++;
    }
    for (int i = Y_POS_MAIN_FRAME_BEGIN + line + 3; i < (Y_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_HEIGHT); i++) {
        gotoXY(X_POS_MAIN_FRAME_BEGIN + 1, i);
        cout << "                        ";
    }
}

//======== CONVERT MEAN SANG MANG CON TRO DE DUNG THANH SANG===============================
struct ArrayMean {
    Mean* arr[50] = {NULL};
    int n = -1;
};

void convertToArray(Mean* w, ArrayMean& l) {
    for (Mean* k = w; k != NULL; k = k->next)
        l.arr[++l.n] = k;
}
//=======================================================================

// Ham hien thi thong tin tu
void showInfoWord(Word* w) {
    if (w) {
        // Xoa tu KO TON TAI NGHIA
        gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
        TextColor(COLOR_DEFAULT);
        cout << "              ";

        // In tu tieng Anh
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 3);
        if (w->tu.empty()) { // Neu tu rong thi in "new_Word"
            cout << "new_Word";
            clearUseSpace(w->tu.length(), 16);
        } else {
            cout << w->tu;
            clearUseSpace(w->tu.length(), 24);
        }

        // In loai tu
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 6);
        cout << "*" << w->loaiTu;
        clearUseSpace(w->loaiTu.length(), 15);

        // Xoa nghiaThem truoc khi in
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 8);
        cout << "   ";
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 13);
        cout << "   ";

        // In cac nghiaThem
        int dem = 0;
        if (w->tv != NULL) {
            for (Mean* k = w->tv; k != NULL && dem < 4; k = k->next) {
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15, Y_POS_MAIN_FRAME_BEGIN + 9 + dem);
                cout << k->data;
                clearUseSpace(k->data.length(), 21);
                dem++;
            }
        } else {
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15, Y_POS_MAIN_FRAME_BEGIN + 9);
            cout << "Rong! ";
            TextColor(COLOR_BUTTON);
            cout << "Ins";
            TextColor(COLOR_DEFAULT);
            cout << " them nghia ";
            dem++;
        }

        // Xoa nghiaThem cua tu truoc (tu vi tri dem)
        for (int i = dem; i < 4; i++) {
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15, Y_POS_MAIN_FRAME_BEGIN + 9 + i);
            cout << "                    ";
        }

        // In cac vd
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 16);
        cout << "Example:";
        string temp;
        int i = 0;
        if (w->viDu[0] != NULL) {
            for (i = 0; i < 5 && w->viDu[i] != NULL; i++) {
                temp = *(w->viDu[i]);
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 17 + i);
                cout << "- " << temp;
                clearUseSpace(temp.length(), 58);
            }
        } else {
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 17);
            cout << "- Vi du rong! Nhan ";
            TextColor(COLOR_BUTTON);
            cout << "Insert";
            TextColor(COLOR_DEFAULT);
            cout << " de them vi du                      ";
            i++;
        }

        for (; i < 5; i++) {
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 17 + i);
            cout << "                                                            ";
        }
    } else {
        gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
        TextColor(COLOR_MESSAGE);
        cout << "TU KO TON TAI!";
        clearInfoWord();
    }

}

// Ham hien thi danh sach cac nghia co thanh sang
void showMeanList(ArrayMean l, int beginFrame, int endFrame, int posHighlight) {
    if (l.arr[0] != NULL) {
        for (int i = beginFrame; i <= endFrame; i++) {
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15, Y_POS_MAIN_FRAME_BEGIN + 9 + i - beginFrame);
            if (i == posHighlight) {
                TextColor(COLOR_HIGH_LIGHT);
                cout << l.arr[i]->data;
                clearUseSpace(l.arr[i]->data.length(), 21);
                TextColor(COLOR_DEFAULT);
            } else {
                cout << l.arr[i]->data;
                clearUseSpace(l.arr[i]->data.length(), 21);
            }
        }
        for (int i = endFrame + 1; i < 4; i++) // 3
        {
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15, Y_POS_MAIN_FRAME_BEGIN + 9 + i);
            cout << "                      ";
        }
    } else {
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15, Y_POS_MAIN_FRAME_BEGIN + 9);
        TextColor(COLOR_HIGH_LIGHT);
        cout << "Rong! ";
        TextColor(COLOR_BUTTON_MESSAGE);
        cout << "Ins";
        TextColor(COLOR_HIGH_LIGHT);
        cout << " them nghia ";
        TextColor(COLOR_DEFAULT);
    }
}

bool checkMeanExist(Mean* head, string nghiaThem) {
    chuanHoaNghia(nghiaThem);
    for (Mean* k = head; k; k = k->next)
        if (k->data == nghiaThem)
            return true;
    return false;
}

// Ham xu ly tab nghia
void scrollMean(Mean*& m, int& t, int& tTemp, Word*& curr, char& k, bool checkInsert) {
    ArrayMean l;
    convertToArray(m, l);
    int beginFrame = 0;
    int posHighlight = 0;
    int endFrame = l.n < 4 ? l.n : 3;

    while (true) {
        // An hien ^ v
        if (l.n >= 4) {
            if (endFrame < l.n) {
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 13);
                TextColor(COLOR_HIGH_LIGHT_KEY);
                cout << " v ";
                TextColor(COLOR_DEFAULT);

                if (beginFrame > 0) {
                    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 8);
                    TextColor(COLOR_HIGH_LIGHT_KEY);
                    cout << " ^ ";
                    TextColor(COLOR_DEFAULT);
                } else {
                    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 8);
                    cout << "   ";
                }
            } else { // endFrame == l.n
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 13);
                cout << "   ";
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 8);
                TextColor(COLOR_HIGH_LIGHT_KEY);
                cout << " ^ ";
                TextColor(COLOR_DEFAULT);
            }
        } else {
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 24, Y_POS_MAIN_FRAME_BEGIN + 13);
            cout << "   ";
        }

        showMeanList(l, beginFrame, endFrame, posHighlight);
        k = _getch();
        if (k == -32) {
            k = _getch();
            if (k == UP) {
                if (posHighlight > 0) {
                    if (posHighlight == beginFrame) {
                        beginFrame--;
                        endFrame--;
                    }
                    posHighlight--;
                }
            } else if (k == DOWN) {
                if (posHighlight < l.n) {
                    if (posHighlight == endFrame) {
                        beginFrame++;
                        endFrame++;
                    }
                    posHighlight++;
                }
            } else if (k == INSERT) {
                string nghiaThem = "";
                Nocursortype(TRUE);
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 3, Y_POS_MAIN_FRAME_BEGIN + 14);
                cout << "Nghia them: ";

                char x;
                while (true) {
                    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15 + nghiaThem.length(), Y_POS_MAIN_FRAME_BEGIN + 14);
                    x = _getch();
                    if (x == -32 || x == 0) {
                        x = _getch();
                    } else if (((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || x == ' ') && nghiaThem.length() < 20) {
                        nghiaThem += x;
                        cout << x;
                        if (checkMeanExist(m, nghiaThem)) {
                            gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                            TextColor(COLOR_MESSAGE);
                            cout << "!!!NGHIA DA TON TAI!";
                            TextColor(COLOR_DEFAULT);
                        } else {
                            gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                            TextColor(COLOR_DEFAULT);
                            cout << "                    ";
                        }
                    } else if (x == BKSP && !nghiaThem.empty()) {
                        nghiaThem.erase(nghiaThem.length() - 1, 1);
                        cout << "\b \b";
                        if (checkMeanExist(m, nghiaThem)) {
                            gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                            TextColor(COLOR_MESSAGE);
                            cout << "!!!NGHIA DA TON TAI!";
                            TextColor(COLOR_DEFAULT);
                        } else {
                            gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                            TextColor(COLOR_DEFAULT);
                            cout << "                    ";
                        }
                    } else if (x == ENTER && !nghiaThem.empty() && !checkMeanExist(m, nghiaThem)) {
                        Nocursortype(FALSE);
                        chuanHoaNghia(nghiaThem);
                        Mean* p = new Mean;
                        p->next = NULL;
                        p->data = nghiaThem;
                        addMean(curr->tv, p);

                        l.arr[++l.n] = p;
                        endFrame = l.n;
                        beginFrame = endFrame < 3 ? 0 : l.n - 3;
                        posHighlight = l.n;
                        break;
                    } else if (x == ESC) {
                        Nocursortype(false);
                        if (showMenuConfirmNoChange() == ENTER) {
                            break;
                        } else {
                            Nocursortype(true);
                        }
                    }
                }
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 3, Y_POS_MAIN_FRAME_BEGIN + 14);
                cout << "                                 ";
            } else if (k == DEL) {
                if (l.n > 0) {
                    if (showMenuConfirmDelete() == ENTER) {
                        removeMean(curr->tv, l.arr[posHighlight]->data); // xoa trong HashTable
                        for (int i = posHighlight + 1; i <= l.n; i++) {
                            l.arr[i - 1] = l.arr[i];
                        }
                        l.arr[l.n] = NULL;
                        l.n--;
                        endFrame = l.n < 4 ? l.n : 3;
                        beginFrame = 0;
                        posHighlight = 0;
                    }
                } else {
                    gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                    TextColor(COLOR_MESSAGE);
                    cout << "!!! KO THE XOA (1 TU PHAI CO TOI THIEU 1 NGHIA)";
                    TextColor(COLOR_DEFAULT);
                    _getch();
                    gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                    cout << "                                               ";
                }
            }
        } else if (k == 0) {
            k = _getch();
            if (k == F10 && checkInsert) {
                return;
            }
        } else if (k == TAB) {
            return;
        } else if (k == ENTER && l.arr[0] != NULL) {
            Nocursortype(TRUE);
            char x;
            string temp = l.arr[posHighlight]->data;
            while (true) {
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15 + temp.length(), Y_POS_MAIN_FRAME_BEGIN + 9 + posHighlight - beginFrame);
                x = _getch();
                if (x == -32 || x == 0) {
                    x = _getch();
                } else {
                    if (x == BKSP && !temp.empty()) {
                        temp.erase(temp.length() - 1, 1);
                        TextColor(COLOR_HIGH_LIGHT);
                        cout << "\b \b";
                        TextColor(COLOR_DEFAULT);
                    } else if (((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || x == ' ') && temp.length() < 20) {
                        TextColor(COLOR_HIGH_LIGHT);
                        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 15 + temp.length(), Y_POS_MAIN_FRAME_BEGIN + 9 + posHighlight - beginFrame);
                        cout << x;
                        temp += x;
                        TextColor(COLOR_DEFAULT);
                    } else if (x == ENTER && !temp.empty()) {
                        Nocursortype(FALSE);
                        chuanHoaNghia(temp);
                        if (showMenuConfirmSave() == ENTER) {
                            Nocursortype(false);
                            l.arr[posHighlight]->data = temp;
                            break;
                        } else {
                            Nocursortype(true);
                        }
                    } else if (x == ESC) {
                        Nocursortype(false);
                        if (showMenuConfirmNoChange() == ENTER)
                            break;
                        else {
                            Nocursortype(true);
                        }
                    }
                }
            }
        } else if (k == ESC) {
            tTemp = t;
            t = -1;
            Nocursortype(TRUE);
            break;
        }
    }
}

// Ham xoa vi du
void removeExample(string* vd[], int posHighlight, int& line) {
    string* temp = vd[posHighlight];
    for (int i = posHighlight + 1; i < line; i++)
        vd[i - 1] = vd[i];
    vd[line - 1] = NULL;
    line--;
    delete temp;
}

// Ham hien thi cac vi du
void showExampleList(string* vd[], int& line, int posHighlight) {
    if (vd[0] == NULL) {
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 17);
        cout << "                                                            ";
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 17);
        TextColor(COLOR_HIGH_LIGHT);
        cout << "- Vi du rong! Nhan ";
        TextColor(COLOR_BUTTON_MESSAGE);
        cout << "Insert";
        TextColor(COLOR_HIGH_LIGHT);
        cout << " de them vi du";
        cout << "                     ";
        TextColor(COLOR_DEFAULT);
    } else {
        for (int i = 0; i < 5; i++) {
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 17 + i);
            if (vd[i] != NULL) {
                if (i == posHighlight) {
                    TextColor(COLOR_HIGH_LIGHT);
                    cout << "- " << *vd[i];
                    clearUseSpace((*vd[i]).length(), 58);
                    TextColor(COLOR_DEFAULT);
                } else {
                    cout << "- " << *vd[i];
                    clearUseSpace((*vd[i]).length(), 58);
                }
                line++;
            } else {
                cout << "                                                            ";
            }
        }
    }
}

// Ham them vi du
void insertExample(string* vd[], int& line, int& posHighlight) {
    string vDThem = "";
    char k;
    Nocursortype(TRUE);
    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 3, Y_POS_MAIN_FRAME_BEGIN + 22);
    cout << "VD them: ";
    while (true) {
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 12 + vDThem.length(), Y_POS_MAIN_FRAME_BEGIN + 22);
        k = _getch();
        if (k == -32 || k == 0) {
            k = _getch();
        } else {
            if (((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z') || (k >= '0' && k <= '9') || k == ' ' || k == ',' || k == '.' || k == 39 || k == '?' || k == '!') && vDThem.length() <= 57) {
                vDThem += k;
                cout << k;
            } else if (k == BKSP && !vDThem.empty()) {
                cout << "\b \b";
                vDThem.erase(vDThem.length() - 1, 1);
            } else if (k == ENTER && !vDThem.empty()) {
                Nocursortype(FALSE);
                chuanHoaViDu(vDThem);
                vd[line] = new string;
                *vd[line] = vDThem;
                posHighlight = line;
                break;
            } else if (k == ESC) {
                Nocursortype(false);
                if (showMenuConfirmNoChange() == ENTER)
                    break;
                else {
                    Nocursortype(true);
                }
            }
        }
    }

    // xoa phan "VD them:................."
    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 3, Y_POS_MAIN_FRAME_BEGIN + 22);
    cout << "                                                                          ";
}

// Ham xu li tab vi du
void scrollExample(string* vd[], int& t, int& tTemp, char& k, bool checkInsert) {
    int posHighlight = 0;
    while (true) {
        int line = 0;
        showExampleList(vd, line, posHighlight);

        k = _getch();
        if (k == -32) {
            k = _getch();
            if (k == UP) {
                if (posHighlight > 0)
                    posHighlight--;
            } else if (k == DOWN) {
                if (posHighlight < line - 1)
                    posHighlight++;
            } else if (k == DEL && vd[0] != NULL) {
                if (showMenuConfirmDelete() == ENTER) {
                    removeExample(vd, posHighlight, line);
                    posHighlight = 0;
                }
            } else if (k == INSERT) {
                if (vd[4] != NULL) {
                    gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                    TextColor(COLOR_MESSAGE);
                    cout << "Toi da 5 vi du! Khong the them VD";
                    TextColor(COLOR_DEFAULT);
                    // dung getch de ko phai dung Sleep
                    char tempKey = ' ';
                    tempKey = _getch();
                    if (tempKey == -32 || tempKey == 0) {
                        tempKey = _getch();
                    }
                    gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                    cout << "                                 ";
                } else {
                    insertExample(vd, line, posHighlight);
                }
            }
        } else if (k == 0) {
            k = _getch();
            if (k == F10 && checkInsert) {
                return;
            }
        } else if (k == TAB) {
            return;
        } else if (k == ENTER && vd[0] != NULL) { // Sua lai "\b \b" de ko bi lag {
            char x;
            string temp = (*vd[posHighlight]);
            while (true) {
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 12 + temp.length(), Y_POS_MAIN_FRAME_BEGIN + 17 + posHighlight); // cho con tro den vi tri cuoi temp
                Nocursortype(true);
                x = _getch();
                if (x == -32 || x == 0) {
                    x = _getch();
                } else {
                    if (x == BKSP) {
                        if (!temp.empty()) {
                            temp.erase(temp.length() - 1, 1);
                            TextColor(COLOR_HIGH_LIGHT);
                            cout << "\b \b";
                            TextColor(COLOR_DEFAULT);
                        }
                    } else if (((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z' || (x >= '0' && x <= '9')) || x == ' ' || x == ',' || x == '.' || x == 39 || x == '?' || x == '!') && temp.length() <= 57) {
                        temp += x;
                        TextColor(COLOR_HIGH_LIGHT);
                        cout << x;
                        TextColor(COLOR_DEFAULT);
                    } else if (x == ENTER && !temp.empty()) {
                        Nocursortype(false);
                        chuanHoaViDu(temp);
                        if (showMenuConfirmSave() == ENTER) {
                            if (!temp.empty())
                                (*vd[posHighlight]) = temp;
                            break;
                        }
                    } else if (x == ESC) {
                        Nocursortype(FALSE);
                        if (showMenuConfirmNoChange() == ENTER)
                            break;
                        else if (x == ESC)
                            Nocursortype(true);
                    }
                }
            }
        } else if (k == ESC) {
            Nocursortype(true);
            tTemp = t;
            t = -1;
            break;
        }
    }
}

// Ham xu li, chinh sua loai tu
void editWordType(string& loaiTu, char& k, int& t, int& tTemp, bool checkInsert) {
    int vt = 0;
    string temp[] = {"Dong tu", "Danh tu", "Tinh tu", "Trang tu", "Dai tu"};
    for (int i = 0; i < 5; i++) {
        if (temp[i] == loaiTu) {
            vt = i;
            break;
        }
    }

    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 6);
    cout << "*";
    TextColor(COLOR_HIGH_LIGHT);
    cout << loaiTu;
    clearUseSpace(loaiTu.length(), 15);
    TextColor(COLOR_DEFAULT);

    k = _getch();
    if (k == 0) {
        k = _getch();
        if (k == F10 && checkInsert) {
            return;
        }
    } else if (k == TAB) {
        return;
    } else if (k == ENTER) {
        char x;
        while (true) {
            TextColor(COLOR_HIGH_LIGHT_KEY);
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 6);
            cout << "<";
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 25, Y_POS_MAIN_FRAME_BEGIN + 6);
            cout << ">";

            TextColor(COLOR_HIGH_LIGHT);
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 11, Y_POS_MAIN_FRAME_BEGIN + 6);
            for (int i = 0; i < 8 - (temp[vt].length() / 2); i++)
                cout << " ";
            gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 18 - (temp[vt].length() / 2), Y_POS_MAIN_FRAME_BEGIN + 6);
            cout << temp[vt];
            for (int i = 8 + (temp[vt].length() / 2); i < 14; i++)
                cout << " ";
            TextColor(COLOR_DEFAULT);

            x = _getch();
            if (x == -32) {
                x = _getch();
                if (x == LEFT) {
                    if (vt > 0)
                        vt--;
                    else if (vt == 0)
                        vt = 4;
                } else if (x == RIGHT) {
                    if (vt < 4)
                        vt++;
                    else if (vt == 4)
                        vt = 0;
                }
            } else if (x == ENTER) {
                if (showMenuConfirmSave() == ENTER) {
                    loaiTu = temp[vt];
                    break;
                }
            } else if (x == ESC) {
                if (showMenuConfirmNoChange() == ENTER)
                    break;
            }
        }
    } else if (k == ESC) {
        tTemp = t;
        t = -1;
    }
}

// Ham xu li khi nhan phim tab: loai tu -> nghia -> vi du
void xuLiTab(Word*& curr) {
    bool checkInsert = false;
    char k;
    int t = 0;
    int tTemp = t;
    while (true) {
        if (t == -1) {
            showHotkeysMainGuide();
            showInfoWord(curr);
            break;
        } else if (t == 0) {
            deleteHotkeysGuide();
            showHotkeysWordAndWordType();
            showInfoWord(curr);
            editWordType(curr->loaiTu, k, t, tTemp, checkInsert);
        } else if (t == 1) {
            deleteHotkeysGuide();
            showHotkeysMeanAndExample();
            showInfoWord(curr);
            scrollMean(curr->tv, t, tTemp, curr, k, checkInsert);
        } else if (t == 2) {
            deleteHotkeysGuide();
            showHotkeysMeanAndExample();
            showInfoWord(curr);
            scrollExample(curr->viDu, t, tTemp, k, checkInsert);
        }

        if (k == TAB && t < 3) {
            t++;
            if (t == 3)
                t = 0;
        }
    }
}

// Ham giai phong mot tu
void freeWord(Word*& w) {
    Mean* del = NULL;
    Mean* head = w->tv;
    while (head != NULL) {
        del = head;
        head = head->next;
        delete del;
    }
    for (int i = 0; i < 5 && w->viDu[i] != NULL; i++)
        delete w->viDu[i];
    delete w;
}

// Ham xoa tu
void removeWord(WordList HashTable[], Word*& wordDel) {
    if (wordDel) {
        int index = hashCode(wordDel->tu);
        Word* head = HashTable[index].head, * tail = HashTable[index].tail;
        if (wordDel == head) {
            if (!head->next) {
                head = tail = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
            }
        } else if (wordDel == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            Word* left = wordDel->prev, * right = wordDel->next;
            right->prev = left;
            left->next = right;
        }
        HashTable[index].head = head;
        HashTable[index].tail = tail;
        freeWord(wordDel);
    }
}

// Ham xu li thanh sang khi xoa tu
void xuLiRemoveWord(WordList HashTable[], Word*& wordBeginFrame, Word*& wordEndFrame, Word*& curr, string str) {
    Word* del = curr;

    if (curr == wordBeginFrame) { // TH1: 
        if (findWordLeft(HashTable, wordBeginFrame) && findWordLeft(HashTable, wordBeginFrame)->tu.find(str) == 0) { // Truoc wordBeginFrame con 
            if (findWordRight(HashTable, wordEndFrame) == NULL || findWordRight(HashTable, wordEndFrame)->tu.find(str) != 0) // Sau wordEndFrame het
                wordBeginFrame = findWordLeft(HashTable, wordBeginFrame);
            else // Sau wordEndFrame van con
                wordBeginFrame = findWordRight(HashTable, wordBeginFrame);
        } else { // Truoc wordBeginFrame het 
            if (wordBeginFrame == wordEndFrame) // List con 1 phan tu
                wordBeginFrame = NULL;
            else // 
                wordBeginFrame = findWordRight(HashTable, wordBeginFrame);
        }
        curr = wordBeginFrame;
        removeWord(HashTable, del);
        wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
    } else if (curr == wordEndFrame) { // TH2:
        if (!findWordRight(HashTable, wordEndFrame) || findWordRight(HashTable, wordEndFrame)->tu.find(str) != 0) { // Sau wordEndFrame het
            if (findWordLeft(HashTable, wordBeginFrame) && findWordLeft(HashTable, wordBeginFrame)->tu.find(str) == 0) // Truoc wordBeginFrame con
                wordBeginFrame = findWordLeft(HashTable, wordBeginFrame);
        }
        removeWord(HashTable, del);
        wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
        curr = wordEndFrame;
    } else { // TH3: curr o giua
        if (!findWordRight(HashTable, wordEndFrame) || findWordRight(HashTable, wordEndFrame)->tu.find(str) != 0) { // Sau wordEndFrame het 
            if (findWordLeft(HashTable, wordBeginFrame) && findWordLeft(HashTable, wordBeginFrame)->tu.find(str) == 0) { // Truoc wordBeginFrame con 
                wordBeginFrame = findWordLeft(HashTable, wordBeginFrame);
                curr = findWordLeft(HashTable, curr);
            } else { // Truoc wordBeginFrame cung het luon
                curr = findWordRight(HashTable, curr);
            }
        } else { // Sau wordEndFrame con
            curr = findWordRight(HashTable, curr);
        }
        //removeWordCurrent(HashTable, del);
        removeWord(HashTable, del);
        wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
    }
}

// Ham tao mot tu moi
Word* createWord() {
    Word* w = new Word;
    w->next = NULL;
    w->prev = NULL;
    w->tu = "";
    w->loaiTu = "loai_tu";
    w->tv = NULL;
    for (int i = 0; i < 5; i++)
        w->viDu[i] = NULL;
    return w;
}

// Ham them tu moi
void addWord(Word*& head, Word*& tail, Word* wordNew) {
    // accept  bill  baby  display  key
    if (!head) {
        head = tail = wordNew;
    } else {
        if (wordNew->tu < head->tu) {
            head->prev = wordNew;
            wordNew->next = head;
            head = wordNew;
        } else if (wordNew->tu > tail->tu) {
            wordNew->prev = tail;
            tail->next = wordNew;
            tail = wordNew;
        } else {
            Word* curr = head->next;
            while ((curr->tu < wordNew->tu) && curr->next) {
                curr = curr->next;
            }
            Word* left = curr->prev;
            curr->prev = wordNew;
            wordNew->next = curr;
            wordNew->prev = left;
            left->next = wordNew;
        }
    }
}

bool checkWordExist(WordList HashTable[], string temp) {
    chuanHoaNghia(temp);
    int idx = hashCode(temp);
    for (Word* k = HashTable[idx].head; !temp.empty() && k != NULL; k = k->next)
        if (k->tu == temp)
            return true;
    return false;
}

// Ham sua tu
void editWord(char& k, int& t, int& tTemp, WordList HashTable[], string& tu, bool checkInsert) {
	// tTemp dung trong xuLiTabInsert => luu gia tri t khi nhan (ESC ESC)
    while (true) {
        string temp = tu;
        // in tu tieng Anh
        gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 3);
        if (temp.empty()) {
            TextColor(24);
            cout << "new_Word";
            clearUseSpace(temp.length(), 16);
        } else {
            TextColor(COLOR_HIGH_LIGHT);
            cout << temp;
            clearUseSpace(temp.length(), 24);
        }
        TextColor(COLOR_DEFAULT);

        k = _getch();
        if (k == -32) {
            k = _getch();
        } else if (k == 0) {
            k = _getch();
            if (k == F10 && checkInsert)
                return;
        } else if (k == TAB) {
            return;
        } else if (k == ENTER) {
            Nocursortype(true);
            char x;
            while (true) {
                gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10 + temp.length(), Y_POS_MAIN_FRAME_BEGIN + 3);
                if (temp.empty()) { // Neu tu rong thi in "new_Word"
                    TextColor(24);
                    cout << "new_Word";
                    clearUseSpace(temp.length(), 16);
                    gotoXY(X_POS_MAIN_FRAME_BEGIN + MAIN_FRAME_WIDTH + 10, Y_POS_MAIN_FRAME_BEGIN + 3);
                    TextColor(COLOR_DEFAULT);
                }

                x = _getch();
                if (x == -32 || x == 0) {
                    x = _getch();
                } else {
                    if (x == BKSP && !temp.empty()) {
                        temp.erase(temp.length() - 1, 1);
                        TextColor(COLOR_HIGH_LIGHT);
                        cout << "\b \b";
                        if (checkWordExist(HashTable, temp)) { // Tu them vao da ton tai
                            gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                            TextColor(COLOR_MESSAGE);
                            cout << "!!!TU DA TON TAI!";
                            TextColor(COLOR_DEFAULT);
                        } else {
                            TextColor(COLOR_DEFAULT);
                            gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                            cout << "                 ";
                        }
                    } else if (((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) && temp.length() < 23) {
                        temp += x;
                        TextColor(COLOR_HIGH_LIGHT);
                        cout << x;
                        clearUseSpace(temp.length(), 24);
						                       
                        if (checkWordExist(HashTable, temp)) { // Tu them vao da ton tai						
                            gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                            TextColor(COLOR_MESSAGE);
                            cout << "!!!TU DA TON TAI!";
                            TextColor(COLOR_DEFAULT);
                        } else {
                            TextColor(COLOR_DEFAULT);
                            gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                            cout << "                 ";
                        }
                    } else if (x == ENTER && !temp.empty() && !checkWordExist(HashTable, temp)) {
                        Nocursortype(false);
                        chuanHoaNghia(temp);
                        tu = temp;
                        break;
                    } else if (x == ESC) {
                        Nocursortype(false);
                        if (showMenuConfirmNoChange() == ENTER)
                            break;
                        else
                            Nocursortype(true);
                    }
                }
            }
        } else if (k == ESC) {
            return; // Chuyen sang ham xu xuLiTabInsert
        }
    }
}

// Ham xu li khi nhan Tab: tu -> loai tu -> nghia -> vi du (giong ham xuLiTab nhung ham nay co tab tu khi them tu moi)
void xuLiTabInsert(Word*& w, WordList HashTable[], Word*& curr, Word*& wordBeginFrame, Word*& wordEndFrame, string& str) {
    bool checkInsert = true;
    char k;
    int t = 0;
    int tTemp = t;
    while (true) {
        Nocursortype(false);
        if (t == 0) {
            deleteHotkeysGuide();
            showHotkeysWordAndWordTypeIns();
            showInfoWord(w);
            editWord(k, t, tTemp, HashTable, w->tu, checkInsert);
        } else if (t == 1) {
            deleteHotkeysGuide();
            showHotkeysWordAndWordTypeIns();
            showInfoWord(w);
            editWordType(w->loaiTu, k, t, tTemp, checkInsert);
        } else if (t == 2) {
            deleteHotkeysGuide();
            showHotkeysMeanAndExampleIns();
            showInfoWord(w);
            scrollMean(w->tv, t, tTemp, w, k, checkInsert);
        } else if (t == 3) {
            deleteHotkeysGuide();
            showHotkeysMeanAndExampleIns();
            showInfoWord(w);
            scrollExample(w->viDu, t, tTemp, k, checkInsert);
        }

        if (k == TAB && t < 4) {
            t++;
            if (t == 4)
                t = 0;
        }

        if (k == F10) {
            if (w->tu.empty()) {
                gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                TextColor(COLOR_MESSAGE);
                cout << "!!!VUI LONG NHAP TU";
                TextColor(COLOR_DEFAULT);
                _getch();
                gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                cout << "                        ";
            } else if (w->loaiTu == "loai_tu") {
                gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                TextColor(COLOR_MESSAGE);
                cout << "!!!VUI LONG CHON LOAI TU";
                TextColor(COLOR_DEFAULT);
                _getch();
                gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                cout << "                        ";
            } else if (w->tv == NULL) {
                gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                TextColor(COLOR_MESSAGE);
                cout << "!!!VUI LONG NHAP NGHIA";
                TextColor(COLOR_DEFAULT);
                _getch();
                gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                cout << "                      ";
            } else {
                if (showMenuConfirmSaveWord() == ENTER) {
                    int index = hashCode(w->tu);
                    addWord(HashTable[index].head, HashTable[index].tail, w);
                    wordBeginFrame = w;
                    curr = w;
                    str = "";
                    wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
                    gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                    TextColor(COLOR_MESSAGE);
                    cout << "DA THEM";
                    TextColor(COLOR_DEFAULT);
                    Sleep(700);
                    gotoXY(X_POS_MESSAGE_BEGIN + 10, Y_POS_MESSAGE_BEGIN + 3);
                    cout << "       ";
					
					deleteHotkeysGuide();
                    showHotkeysMainGuide();
                    return;
                }
            }
        }

        if (k == ESC) {
            Nocursortype(false);
            if (showMenuConfirmCancel() == ENTER) {
                Nocursortype(true);
                showHotkeysMainGuide();
                showInfoWord(curr);
                freeWord(w); // Giai phong w da khoi tao truoc do
                return;
            } else t = tTemp;
        }
    }
}
//===============================================================================================================================

// Ham chinh go tu can tra hoac dung thanh sang de tra
void searchWord(WordList HashTable[]) {
    char ch;
    string str = "";
    Word* wordHome = NULL;
    findFirstWord(HashTable, wordHome);
    Word* wordBeginFrame = wordHome;
    Word* curr = wordBeginFrame;
    Word* wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
    bool strCheck = true; // phat hien chuoi moi nhap vao khac chuoi truoc do
    
    drawMainFrame();
    showHotkeysMainGuide();
    
    while (true) {
        if (strCheck) {
            if (!str.empty()) {
                wordBeginFrame = findFirstWordStr(HashTable, str);
                curr = wordBeginFrame;
                wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
            } else {
                findFirstWord(HashTable, wordHome);
                wordBeginFrame = curr = wordHome;
                wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
            }
        }
        showWordList(HashTable, curr, wordBeginFrame, wordEndFrame);
        showInfoWord(curr);

        gotoXY(X_POS_MAIN_FRAME_BEGIN + 1 + str.length(), Y_POS_MAIN_FRAME_BEGIN + 1);
        if (str.empty()) {
            TextColor(127);
            cout << "Tim kiem";
            clearUseSpace(8, 23);
            gotoXY(X_POS_MAIN_FRAME_BEGIN + 1, Y_POS_MAIN_FRAME_BEGIN + 1);
            TextColor(COLOR_DEFAULT);
        }

        Nocursortype(true);
        ch = _getch();
        Nocursortype(false);
        if (ch == -32 || ch == 0) {
            ch = _getch();
            if (ch == UP) {
                if (findWordLeft(HashTable, curr) != NULL && findWordLeft(HashTable, curr)->tu.find(str) == 0) {
                    if (curr == wordBeginFrame) {
                        wordBeginFrame = findWordLeft(HashTable, wordBeginFrame);
                        wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
                    }
                    curr = findWordLeft(HashTable, curr);
                }
                strCheck = false;
            } else if (ch == DOWN) {
                if (findWordRight(HashTable, curr) != NULL && findWordRight(HashTable, curr)->tu.find(str) == 0) {
                    if (curr == wordEndFrame) {
                        wordBeginFrame = findWordRight(HashTable, wordBeginFrame);
                        wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
                    }
                    curr = findWordRight(HashTable, curr);
                }
                strCheck = false;
            } else if (ch == HOME) {
                str = "";
                wordBeginFrame = wordHome;
                curr = wordBeginFrame;
                wordEndFrame = findWordEndFrame(HashTable, wordBeginFrame, str);
            } else if (ch == DEL && curr) {
                if (showMenuConfirmDelete() == ENTER) {
                    xuLiRemoveWord(HashTable, wordBeginFrame, wordEndFrame, curr, str);
                }
            } else if (ch == INSERT) {
                Word* w = createWord();
                xuLiTabInsert(w, HashTable, curr, wordBeginFrame, wordEndFrame, str);
                strCheck = false;
            }
        } else if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && str.length() < 23) {
            cout << ch;
            clearUseSpace(str.length(), 23);
            strCheck = true;
            str += ch;
            _strlwr((char*) str.c_str());
        } else if (ch == BKSP && !str.empty()) {
            strCheck = true;
            str.erase(str.length() - 1, 1);
            cout << "\b \b";
        } else if (ch == TAB && curr != NULL) {
            Nocursortype(FALSE);
            xuLiTab(curr);
            Nocursortype(TRUE);
        } else if (ch == ESC) {
            Nocursortype(FALSE);
            if (showMenuConfirmExit() == ENTER)
                return;
            else
                Nocursortype(true);
        }
    }
}

// Ham ghi du lieu ra file data.txt
void writeFile(WordList HashTable[], ofstream& FileOut) {
    string temp = "";
    for (int i = 0; i < 26; i++) {
        for (Word* k = HashTable[i].head; k != NULL; k = k->next) {
            FileOut << k->tu << "|";
            FileOut << k->loaiTu << "|";
            for (Mean* x = k->tv; x != NULL; x = x->next)
                FileOut << x->data << "|";
            FileOut << ".|";
            for (int i = 0; i < 5; i++) {
                if (k->viDu[i] != NULL)
                    FileOut << (*k->viDu[i]) << "|";
                else
                    FileOut << "|";
            }
            if (findWordRight(HashTable, k) != NULL)
                FileOut << "\n";
        }
    }
}

int main() {
    system("color 70");
    resizeConsole(1024, 685);
    
    ifstream fileIn;
    ofstream fileOut;
    WordList HashTable[26];

    fileIn.open("data.txt", ios::in);
    addWordHashTable(HashTable, fileIn);

    showDictionaryArt();
    searchWord(HashTable);
    
    fileOut.open("data.txt", ios::out);
    writeFile(HashTable, fileOut);
    fileIn.close();
    fileOut.close();
    free(HashTable);

    return 0;
}
