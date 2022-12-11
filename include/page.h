#ifndef PAGE_H
#define PAGE_H

#define PAGE_SIZE (sizeof(struct page) + sizeof(struct page_entry) * 2 * order)
#define NIL -1

struct page_entry
{
    int other_page;
    int key;
    int address_to_data;
} __attribute__((packed));

struct page
{
    int records_on_page;
    int parent_page;
    int next_page;
    struct page_entry entries[];
} __attribute__((packed)); 

struct page *page_init(struct page *p, int order);
void page_free(struct page *p);
void set_entry(struct page *p, int entry_index, int key, int address_to_data, int other_page);

#endif