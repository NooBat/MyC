#ifndef _SORTED_LIST_INTERFACE
#define _SORTED_LIST_INTERFACE

template<class ItemType>
class SortedListInterface
{
public:
    virtual ~SortedListInterface()
    {
        return;
    }

    /** Inserts an entry into this sorted list in 
     * its proper order so that the list remains sorted.
     * @pre None.
     * @post newEntry is in the list, and the list is sorted. 
     * @param newEntry The entry to insert into the sorted list. */
    virtual void insertSorted(const ItemType& newEntry) = 0;

    /** Removes the first or only occurence of the given entry from this 
     * sorted list.
     * @pre None.
     * @post If the removal is successful, the first occurence of the 
     * given entry is no longer in the sorted list, and the returned 
     * value is true. Otherwise, the sorted list is unchanged and the
     * returned value is false.
     * @param anEntry The entry to remove.
     * @return True if removal is successful, otherwise false. */
    virtual bool removeSorted(const ItemType& anEntry) = 0;


    /** Gets the position of the first or only occurrence of the given 
     * entry in this sorted list. In case the entry is not in the list, 
     * determines where it should be if it were added to the list.
     * @pre None.
     * @post The position where the given entry is or belongs is returned.
     * The sorted list is unchanged.
     * @param anEntry The entry to locate.
     * @return Either the position of the given entry, if it occurs in the
     * sorted list, or the position where the entry would occur, but as a
     * negative integer. */
    virtual int getPosition(const ItemType& anEntry) = 0;

    /** Sees whether the list is empty.
     * @return True if the list is empty, false otherwise. */
    virtual bool isEmpty() const = 0;

    /** Gets the current number of entries in this list.
     * @return The integer number of entries currently in the list. */
    virtual int getLength() const = 0;

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
    virtual ItemType getEntry(int position) const = 0;
};

#endif