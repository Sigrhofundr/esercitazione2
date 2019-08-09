//
// Created by alber on 20/07/2019.
//

#include <iostream>
#include "Directory.h"
#include "../Base.h"

std::shared_ptr<Directory> Directory::instance = nullptr;

Directory::Directory(std::string name) {
    this->setName(name);
}

/*crea, se ancora non esiste, l’oggetto di tipo Directory e ne restituisce lo smart pointer.*/
std::shared_ptr<Directory> Directory::getRoot() {

    if(Directory::instance == nullptr) {
        Directory::instance = std::shared_ptr<Directory>(new Directory("/"));
        Directory::instance->parent = Directory::instance;
        Directory::instance->self = Directory::instance;
    }

    return instance;

}

/*crea un nuovo oggetto di tipo Directory, il cui nome è desunto dal parametro, e lo aggiunge alla cartella corrente. Se
risulta già presente, nella cartella corrente, un oggetto con il nome indicato, solleva
un’eccezione.*/
std::shared_ptr<Directory> Directory::addDirectory(std::string nome) {

    for(auto const &f : this -> files) {
        if(f->getName() == nome)
            throw std::exception();
    }

    std::shared_ptr<Directory> child = std::shared_ptr<Directory>(new Directory(nome));
    child->parent = this->self;
    child->self = self;

    this->files.push_back(child);

    return child;
}

/*aggiunge alla Directory un nuovo oggetto di tipo File, ricevendone come parametri il nome e la dimensione in byte;
l’aggiunta di un File con nome già presente nella cartella corrente non è permessa e causa
un’eccezione*/
std::shared_ptr<File> Directory::addFile(std::string nome, uintmax_t size) {

    for(auto const &f : this->files) {
        if(f->getName() == nome)
            throw std::exception();
    }

    std::shared_ptr<File> file = std::make_shared<File>(nome,size);

    this->files.push_back(file);

    return file;
}

/*restituisce uno smart pointer all’oggetto
(Directory o File) di nome “name” contenuto nella directory corrente. Se inesistente,
restituisce uno shared_ptr vuoto. I nomi speciali “ .. ” e “ . ” permettono di ottenere
rispettivamente lo shared_pointer alla directory genitore di quella corrente, e quello
all’istanza stessa.*/
std::shared_ptr<Base> Directory::get(std::string name) {
    if(name == ".")
        return this->self.lock();
    if(name == "..")
        return this->parent.lock();

    for(auto const &f : this->files)
    {
        if(name == f->getName())
            return f;
    }

    return std::shared_ptr<Base>();
}

//funziona come il metodo get(nome), facendo un dynamic_pointer_cast dal tipo Base al tipo Directory
std::shared_ptr<Directory> Directory::getDir(std::string name) {
    if(name == ".")
        return this->self.lock();
    if(name == "..")
        return this->parent.lock();

    for(auto const &f : this->files) {
        if(name == f->getName() && f->mType() == 1)
            return std::dynamic_pointer_cast<Directory>(f);
    }
    return std::shared_ptr<Directory>();
}

//funziona come il metodo get(nome), facendo un dynamic_pointer_cast dal tipo Base al tipo File
std::shared_ptr<File> Directory::getFile(std::string name) {

    for(auto const &f : this->files) {
        if(name == f->getName() && f->mType() == 0)
            return std::dynamic_pointer_cast<File>(f);
    }
    return std::shared_ptr<File>();
}

/*rimuove dalla collezione di figli della directory corrente l’oggetto (Directory o File) di nome “nome”.
 * La rimozione degli oggetti di nome “ .. ” e “ . ” non è permessa e causa un’eccezione*/
void Directory::remove(std::string nome) {
    if(nome == "." || nome == "..")
        throw std::exception();
    for(auto const &f : this->files)
        if(nome == f->getName()) {
            this->files.remove(f);
            break;
        }
}

/* implementa il metodo virtuale puro della classe Base; elenca ricorsivamente File e
 * Directory figli della directory corrente, indentati in modo appropriato*/
void Directory::ls(int indent) const {
    for(int i = 0; i< indent; i++)
        std::cout << "\t";
    std::cout << "[+] " <<this->getName() << std::endl;

    auto iter = this->files.begin();
    auto end = this->files.end();
    for(; iter!= end; iter++) {
        (*iter)->ls(indent + 1);
    }
}

int Directory::mType() const {
    return 1;
}