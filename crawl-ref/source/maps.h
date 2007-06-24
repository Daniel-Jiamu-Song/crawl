/*
 *  File:       maps.cc
 *  Summary:    Functions used to create vaults.
 *  Written by: Linley Henzell
 *
 *  Change History (most recent first):
 *
 *               <1>     -/--/--        LRH             Created
 */


#ifndef MAPS_H
#define MAPS_H

#include "FixVec.h"
#include "dungeon.h"
#include "mapdef.h"

#include <vector>

class map_def;
struct vault_placement
{
    int x, y;
    int width, height;
    int orient;
    map_def map;
    std::vector<coord_def> exits;

    vault_placement()
        : x(-1), y(-1), width(0), height(0), map(),
          exits()
    {
    }
};

int vault_main(map_type vgrid, 
               vault_placement &vp,
               int vault_force,
               std::vector<vault_placement> *avoid_vaults = NULL);

const map_def *map_by_index(int index);
int random_map_for_place(const std::string &place, bool mini = false);
int random_map_for_depth(const level_id &lid, bool want_minivault = false);
int random_map_for_tag(const std::string &tag, bool want_minivault,
                       bool check_depth = false);
void add_parsed_map(const map_def &md);

void read_maps();
void run_map_preludes();
void reset_map_parser();
std::string get_descache_path(const std::string &file,
                              const std::string &ext);

extern dlua_chunk map_file_prelude;
extern std::string lc_desfile;
extern map_def     lc_map;
extern level_range lc_range;
extern depth_ranges lc_default_depths;

#endif
