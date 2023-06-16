#include <iostream>
#include <vector>
#include <string>


/*!
    \brief Базовый класс
*/
class Component
{
private:
    /*!
       Форматированный вывод элемента на консоль
       \param[in] level Уровень элемента в структуре
   */
    virtual void print(int level) = 0;
public:
    std::string name;  ///< Название элемента
    /*!
       Виртуальный деструктор
    */
    virtual ~Component() {}

    friend class Chapter;
};

/*!
    \brief Класс для раздела меню
*/
class Chapter : public Component
{
private:
    std::vector<Component*> elements; ///< Вектор вложенных элементов
    /*!
       Форматированный вывод элемента на консоль
       \param[in] level Уровень элемента в структуре
   */
    void print(int level)
    {
        for (int i = 0; i < level; i++)
        {
            std::cout << "   ";
        }
        std::cout << name << ":" << std::endl;

        for (int i = 0; i < elements.size(); i++)
            elements[i]->print(level + 1);
    }
public:
    /*!
       Конструктор раздела меню
       \param[in] name Имя раздела
    */
    Chapter(std::string name)
    {
        this->name = name;
    }

    /*!
       Деструктор
    */
    ~Chapter()
    {
        for (int i = 0; i < elements.size(); i++)
            delete elements[i];
    }

    /*!
       Интерфейс для вывода элемента на экран
    */
    void print()
    {
        print(0);
    }

    /*!
       Добавление элемента в раздел
       \param[in] elem Элемент, добавляемый в раздел
    */
    void addElement(Component* elem)
    {
        elements.push_back(elem);
    }
};

/*!
    \brief Класс для блюда/напитка
*/
class Element : public Component
{
private:
    /*!
       Форматированный вывод элемента на консоль
       \param[in] level Уровень элемента в структуре
   */
    void print(int level)
    {
        for (int i = 0; i < level; i++)
        {
            std::cout << "   ";
        }
        std::cout << "- " << name << std::endl;
    }
public:
    /*!
       Конструктор блюда/напитка
       \param[in] name Имя блюда/напитка
    */
    Element(std::string name)
    {
        this->name = name;
    }
};


/*!
        Вспомогательная функция для создания меню кухни
*/
Chapter* getKitchen()
{
    Chapter* kitchen = new Chapter("Kitchen");

    Chapter* adding = new Chapter("Cold appetizers");
    
    for (std::string name : {"Antipasto Bites", "Greek Feta Dip", "Melon Prosciutto Skewers"})
    {
        Element* addingElement = new Element(name);
        adding->addElement(addingElement);
    }

    kitchen->addElement(adding);

    adding = new Chapter("Hot appetizers");

    for (std::string name : {"Hot Cheese Dip with Bacon", "Crab Stuffed Mushrooms", "Grape Jelly Meatballs"})
    {
        Element* addingElement = new Element(name);
        adding->addElement(addingElement);
    }

    kitchen->addElement(adding);

    adding = new Chapter("Hot appetizers");

    for (std::string name : {"Hot Cheese Dip with Bacon", "Crab Stuffed Mushrooms", "Grape Jelly Meatballs"})
    {
        Element* addingElement = new Element(name);
        adding->addElement(addingElement);
    }

    kitchen->addElement(adding);

    adding = new Chapter("Salads");

    for (std::string name : {"Green Salad", "Easy Pasta Salad", "Creamy Coleslaw"})
    {
        Element* addingElement = new Element(name);
        adding->addElement(addingElement);
    }

    kitchen->addElement(adding);

    adding = new Chapter("Soups");

    for (std::string name : {"Pumpkin soup", "Miso soup", "Lentil soup"})
    {
        Element* addingElement = new Element(name);
        adding->addElement(addingElement);
    }

    kitchen->addElement(adding);

    adding = new Chapter("Main courses");

    Chapter* subCat = new Chapter("Pasta");

    for (std::string name : {"Healthy Pasta with Spicy Crab", "Low-Cal Fettuccine Alfredo", "Ina's Real Meatballs and Spaghetti"})
    {
        Element* addingElement = new Element(name);
        subCat->addElement(addingElement);
    }

    adding->addElement(subCat);

    subCat = new Chapter("Porridge");

    for (std::string name : {"Rice porrige", "Oatmeal"})
    {
        Element* addingElement = new Element(name);
        subCat->addElement(addingElement);
    }

    adding->addElement(subCat);

    kitchen->addElement(adding);

    return kitchen;
}

/*!
        Вспомогательная функция для создания меню бара
*/
Chapter* getBar()
{
    Chapter* bar = new Chapter("Bar");

    Chapter* adding = new Chapter("Soft drinks");

    for (std::string name : {"7Up", "Fanta", "Pepsi"})
    {
        Element* addingElement = new Element(name);
        adding->addElement(addingElement);
    }

    bar->addElement(adding);

    adding = new Chapter("Alcoholic drinks");

    for (std::string name : {"Vodka", "Beer", "Wine"})
    {
        Element* addingElement = new Element(name);
        adding->addElement(addingElement);
    }

    bar->addElement(adding);

    adding = new Chapter("Tea");

    for (std::string name : {"Green tea", "Black Tea"})
    {
        Element* addingElement = new Element(name);
        adding->addElement(addingElement);
    }

    Chapter* subCat = new Chapter("Oolong");

    for (std::string name : {"Milk oolong", "Ginseng oolong"})
    {
        Element* addingElement = new Element(name);
        subCat->addElement(addingElement);
    }

    adding->addElement(subCat);
    bar->addElement(adding);

    adding = new Chapter("Coffee");

    for (std::string name : {"Espresso", "Cappuccino", "Latte"})
    {
        Element* addingElement = new Element(name);
        adding->addElement(addingElement);
    }

    bar->addElement(adding);

    return bar;
}


/*!
        Точка входа в программу
*/
int main()
{
    Chapter menu = Chapter("Menu");

    menu.addElement(getKitchen());
    menu.addElement(getBar());
    menu.print();
}
