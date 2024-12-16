#define i_TYPE Floats, float // Container type (name, element type)
#include "stc/vec.h"         // "instantiate" the desired container type

#define i_implement
#include "stc/cstr.h"

#define i_key_str
#define i_val_str
#include "stc/hmap.h"

#include "pimbs.h"

int main(void)
{
    // Create an unordered_map of three strings (that map to strings)
    hmap_str umap = c_init(hmap_str, {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"}
    });

    // Iterate and print keys and values of unordered map
    c_foreach (n, hmap_str, umap) {
        printf("Key:[%s] Value:[%s]\n", cstr_str(&n.ref->first), cstr_str(&n.ref->second));
    }

    // Add two new entries to the unordered map
    hmap_str_emplace(&umap, "BLACK", "#000000");
    hmap_str_emplace(&umap, "WHITE", "#FFFFFF");

    // Insert only if "CYAN" is not in the map: create mapped value when needed only.
    hmap_str_result res = hmap_str_emplace_key(&umap, "CYAN");
    if (res.inserted)
        res.ref->second = cstr_from("#00FFFF"); // must assign second if key was inserted.

    // Output values by key
    printf("The HEX of color RED is:[%s]\n", cstr_str(hmap_str_at(&umap, "RED")));
    printf("The HEX of color BLACK is:[%s]\n", cstr_str(hmap_str_at(&umap, "BLACK")));

    hmap_str_drop(&umap);
}
