#ifndef GUITARDB_H_
#define GUITARDB_H_

/** Information about a single guitar.
 *
 * All character arrays except for BODY_TYPE should be NUL-terminated
 * character strings. ITEM_KEY must be unique within a given database.
 */
struct guitardb_guitar {
  int item_key;       /** positive integer id number */
  char make[15];      /** Fender, Gibson, Gretsch, etc. */
  char model[15];     /** Telecaster, Les Paul, etc. */
  char submodel[15];  /** Deluxe, Standard, Custom, etc. */
  char body_type[2];  /** SB solid body, HB hollow body,
                       *  SH semihollow
                       */
  int year;           /** year of manufacture */
  char finish[25];    /** description of finish including color,
                       *  binding, etc.
                       */
  int strings;        /** number of strings - usually 6 or 7 or 12 */
  int pickups;        /** number of pickups – usually 1 to 3 */
  char neck;          /** pickup type - H humbucker, C single coil,
                       *  P-90, F Filtertron, N none
                       */
  char middle;        /** same as above */
  char bridge;        /** same as above */
};

/** Allocates and initializes a new empty guitar database.
 *
 * Returns the new database or NULL if out of memory.
 */
struct guitardb *guitardb_create(void);

/** Adds a guitar to the database.
 *
 * Stores a pointer to the guitar (i.e. does not make a copy). The
 * caller is responsible for ensuring the validity of GTAR throughout
 * the lifetime of DB. GTAR->item_key must be unique within DB. The
 * item key must be positive.
 *
 * Returns the item key or -1 if the guitar could not be added to the
 * database.
 */
int guitardb_add(struct guitardb *db, struct guitardb_guitar *gtar);

/** Returns a guitar in the database by its key.
 *
 * The returned guitar is stored internally by the database and must
 * not be freed.
 *
 * Returns the guitar with item key KEY or NULL if no such guitar was
 * found.
 */
struct guitardb_guitar *guitardb_lookup(struct guitardb *db, int key);

/** Removes a guitar from the database by its key.
 *
 * The caller is reponsible for ensuring that the storage for the
 * guitar is eventually freed.
 *
 * Returns 0 on success or -1 if no guitar was found with item key
 * KEY.
 */
int guitardb_delete(struct guitardb *db, int key);

/** Returns the first guitar in the database.
 *
 * Returns the first guitar in the database or NULL if the database is
 * empty.
 */
struct guitardb_guitar *guitardb_first(struct guitardb *db);

/** Returns the next guitar in the database.
 *
 * previous call    | result
 * ------------------------------------------------
 * guitardb_first()  | the second guitar
 * guitardb_next()   | the guitar after the previous
 * guitardb_create() | error
 * guitardb_add()    | error
 * guitardb_delete() | error
 *
 * Returns the next guitar in the database or NULL on error.
 */
struct guitardb_guitar *guitardb_next(struct guitardb *db);

/** Deallocates storage for the database.
 *
 * The database need not be empty, but the caller is always
 * responsible for deallocating the storage for guitars.
 *
 * Returns 0.
 */
int guitardb_destroy(struct guitardb *db);

#endif  /* GUITARDB_H_ */
