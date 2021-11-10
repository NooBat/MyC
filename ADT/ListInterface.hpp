#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template<class T>
class ListInterface {
public:
    virtual ~ListInterface() {
        return;
    }

    /** Sees whether the list is empty.
     * @return True if the list is empty, false otherwise. */
    virtual bool isEmpty() const = 0;

    /** Gets the current number of entries in this list.
     * @return The integer number of entries currently in the list. */
    virtual int getLength() const = 0;

    /** Inserts an entry into the list at a given position.
     * @pre None. 
     * @post If 1 <= position <= getLength() + 1 and the insertion is
     *      successful, newEntry is at the given position in the list,
     *      other entries are renumbered accordingly, and the returned 
     *      value is true.
     * @param newPosition The list position at which to insert newEntry.
     * @param newEntry The entry to insert into the list.
     * @return True if insertion is successful, false otherwise. */
    virtual bool insert(int newPosition, const T& newEntry) = 0;

    /** Removes the entry at a given position from this list.
     * @pre None. 
     * @post if 1 <= position <= getLength() + 1 and the removal is successful,
     *      the entry at the given position in the list is removed, other item
     *      are renumbered accordingly and the returned value is true.
     * @param position The list position of the entry to remove.
     * @return True if removal is successful, false otherwise. */
    virtual bool remove(int postition) = 0;

    /** Removes all entries from this list.
     * @post List contains no entries and the count of item is 0. */
    virtual void clear() = 0;

    /** Gets the entry at the given position in this list.
     * @pre 1 <= position <= getLength().
     * @post The desired entry has been returned.
     * @param position The list position of the desired entry.
     * @return The item at the given position. */
    virtual T getEntry(int position) const = 0;

    /** Replaces the entry at the given position in this list.
     * @pre 1 <= position <= getLength().
     * @post The entry at the given position is newEntry.
     * @param position The list position of the item to replace.
     * @param newEntry The replacement entry. */
    virtual void setEntry(int position, const T& newEntry) = 0;

    /** Gets the position of the list of a given entry.
     * @pre None.
     * @post if targetEntry is in the list and the returned value
     * is 1 <= position <= getLength().
     * @param targetEntry The entry needs to be located.
     * @return The position of the given entry in the list. */
    virtual int getPosition(const T& targetEntry) const = 0;

    /** Sort the list in ascending order.
     * @post A sorted list in ascending order. */
    virtual void sort() = 0;

    // /** Checks whether a given entry is in the list.
    //  * @pre None.
    //  * @post If targetEntry is in the list and the returned 
    //  * value is true;
    //  * @param targetEntry The entry needs to be checked.
    //  * @return True if the list contains the given entry
    //  * false otherwise. */
    // virtual bool contains(const T& targetEntry) const = 0;

    // /** Removes all entries from the list.
    //  * @pre None.
    //  * @post If targetEntry is in the list then the entries
    //  * same with the given entry are deleted and other item will be renumbered
    //  * accordingly.
    //  * @param targetEntry The entry needs to be deleted. */
    // virtual void remove(const T& targetEntry) = 0;
    
};
#endif