#include <iostream>
#include <utility>
using namespace std;

struct Song{
    string data;
    Song* next;
    Song* prev;
};

class Playlist{
    private:
    Song* last = nullptr;
    Song* prev = nullptr;
    Song* curr = nullptr;

    public:
    void addSongFront(string);
    void addSongBack(string);
    void eraseSong(string);
    void nextSong();
    void prevSong();
    void play(string);
    void play();
    bool isEmpty();
    ~Playlist();
};

bool Playlist::isEmpty(){
    return last == nullptr;
}

void Playlist::addSongFront(string song){
    Song* newSong = new Song;
    newSong->data = song;

    if (last == nullptr){
        last = newSong;
        last->next = last;
    } else {
        newSong->next = last->next;
        newSong->next->prev = newSong;
        last->next = newSong;
        newSong->prev = last;
    }
}

void Playlist::addSongBack(string song){
    Song* newSong = new Song;
    newSong->data = song;

    if (last == nullptr){
        last = newSong;
        last->next = last;
    } else {
        newSong->next = last->next;
        newSong->next->prev = newSong;
        last->next = newSong;
        newSong->prev = last;
        last = newSong;
    }
}

void Playlist::play(string song){
    Song* tmp = last->next;

    if(last == nullptr){
        cout << "Playlist is empty.\n";
    } else {
        bool exist = true;
        while(tmp->data != song){ 
            tmp = tmp->next;
            if(tmp == last){
                exist = false;
                break;
            }
        }
        if(exist){
            cout << tmp->data << endl;
            curr = tmp;
        } else {
            cout << "Song does not exist.\n";
        }
    }
}

void Playlist::play(){
    if(last == nullptr){
        cout << "Playlist is empty.\n";
    } else {
        if(curr == nullptr) curr = last->next;
        Song* tmp = curr;

        if(tmp->next == curr) cout << tmp->data << endl;
        else{
            while(tmp != curr->prev){ 
                cout << tmp->data << endl;
                tmp = tmp->next;
            }
            cout << tmp->data << endl;
            curr = tmp;
        }
    }
}

void Playlist::nextSong(){
    curr = curr->next;
    cout << curr->data << endl;
}

void Playlist::prevSong(){
    curr = curr->prev;
    cout << curr->data << endl;
}

void Playlist::eraseSong(string song){
    Song* tmp = last->next;

    if(last == nullptr){
        cout << "Playlist is empty.\n";
    } else {
        bool exist = true;
        while(tmp->data != song){ 
            tmp = tmp->next;
            if(tmp == last){
                exist = false;
                break;
            }
        }
        if(exist){
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
        } else {
            cout << "Song does not exist.\n";
        }
    }
}

Playlist::~Playlist(){
    Song* tmp = last->next;
    last->next = nullptr;
    
    Song* current;
    while(tmp){
        current = tmp;
        tmp = tmp->next;
        delete(current);
    }
}

void playlistDisplay(){
    Playlist p;
    char play;
    do {
        cout << "Sponktipy\n"
             << "[1] - Display Songs\n"
             << "[2] - Play Song\n"
             << "[3] - Next Song\n"
             << "[4] - Previous Song\n"
             << "[5] - Add Song Front\n"
             << "[6] - Add Song Back\n"
             << "[7] - Erase Song\n";

        int choice; cin >> choice;
        string tmp;
        cin.ignore();
        switch(choice){
            case 1:
                p.play();
                break;
            case 2: 
                p.play();
                if(!p.isEmpty()){
                    cout << "Enter Song Title: ";
                    getline(cin, tmp);
                    cout << "Current Track: ";
                    p.play(tmp);
                }
                break;
            case 3:
                p.nextSong();
                break;
            case 4:
                p.prevSong();
                break;
            case 5:
                cout << "Add Song Front\n"
                     << "Enter Song Title: ";
                getline(cin, tmp);
                p.addSongFront(tmp);
                break;
            case 6:
                cout << "Add Song Back\n"
                     << "Enter Song Title: ";
                getline(cin, tmp);
                p.addSongBack(tmp);
                break;
            case 7:
                cout << "Erase Song\n"
                     << "Enter Song Title: ";
                getline(cin, tmp);
                p.eraseSong(tmp);
                break;                
        }
        cout << "Continue? ";
        cin >> play;
        system("clear");
    } while(play == 'Y' || play == 'y');

    cout << "Thank you.\n";
}

int main(){
    playlistDisplay();
}