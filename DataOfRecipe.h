#ifndef DATAOFRECIPE_H_INCLUDED
#define DATAOFRECIPE_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include <string.h>
#include <vector>
#include "Recipe.h"
using namespace std;
class DataOfRecipe : public Recipe
{
public:
    DataOfRecipe();
    void loadRecipe(string filePath);
    void addRecipe(Recipe& recipe);
    void editRecipe(string updateRecipe, Recipe& recipe);
    void saveRecipe(string filePath);
    void deleteRecipe(string dummy);
    void displayAllRecipe();
    void sortByName();


    Recipe& searchRecipeByName(string nameOfRecipe);
    Recipe& searchRecipeByType(string TypeOfRecipe) const;
protected:
    vector <Recipe>recipe;
};

#endif




