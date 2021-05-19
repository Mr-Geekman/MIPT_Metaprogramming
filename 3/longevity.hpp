#ifndef LONGEVITY_HPP
#define LONGEVITY_HPP

#include <memory>
#include <list>
#include <algorithm>


// Тип для хранения в массиве
class GeneralHolder {
public:
    GeneralHolder(unsigned int x) : longevity(x) {}
    virtual ~GeneralHolder() {};
    static bool const compare_pointers(const GeneralHolder* left_ptr, const GeneralHolder* right_ptr) {
        return left_ptr->longevity > right_ptr->longevity;
    }
private:
    unsigned int longevity;
};

// Шаблонная реализация типа для хранения в массиве
template <typename T>
class Holder: public GeneralHolder
{
public:
    Holder(T* p, unsigned int longevity) : GeneralHolder(longevity), tracked(p) {}
    ~Holder() {
        delete tracked;
    }
private:
    T* tracked;
};

// Определяем глоабальную очередь для хранения объектов
std::list<GeneralHolder*>* removing_queue = new std::list<GeneralHolder*>();

// Определяем функцию для обработки удаления объекта
void at_exit_function() {
    // Берем элемент с вершины стека
    GeneralHolder* top_ptr = removing_queue->back();
    // Особождаем место
    removing_queue->pop_back();
    // Удаляем элемент
    delete top_ptr;
    // Удаляем очередь если требуется
    if(removing_queue->empty()) {
        delete removing_queue;
        removing_queue = nullptr;
    }
}

template <typename T>
void set_longevity(T* to_process_ptr, unsigned int longevity) {
    // Если очереди еще нет, то создадим ее
    if(removing_queue == nullptr) {
        removing_queue = new std::list<GeneralHolder*>;
    }

    // Обернем только что созданный объект в умный указатель, чтобы он удалился в случае ошибки
    std::unique_ptr<GeneralHolder> new_ptr(new Holder<T>(to_process_ptr, longevity));

    // Найдем позицию для вставки
    auto pos = std::upper_bound(
            removing_queue->begin(),
            removing_queue->end(),
            new_ptr.get(),
            GeneralHolder::compare_pointers);

    // Вставим элемент в очередь
    removing_queue->insert(pos, new_ptr.get());

    // Если исключение не выбросилось, то уберем обертку
    new_ptr.release();

    // Регистрируем функцию at_exit_function, как выполняющуюся после удаления объекта
    std::atexit(at_exit_function);
}

#endif //LONGEVITY_HPP