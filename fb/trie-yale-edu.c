// http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#Patricia_trees

Trie
trie_insert(Trie trie, const char *key)
{
    int bit;
    int bitvalue;
    Trie t;
    Trie kid;
    const char *oldkey;

    if(trie == 0) {
        return make_trie_node(key);
    }
    /* else */
    /* first we'll search for key */
    for(t = trie, bit = 0; !IsLeaf(t); bit++, t = kid) {
        kid = t->kids[bitvalue = GET_BIT(key, bit)];
        if(kid == 0) {
            /* woohoo! easy case */
            t->kids[bitvalue] = make_trie_node(key);
            return trie;
        }
    }

    /* did we get lucky? */
    if(!strcmp(t->key, key)) {
        /* nothing to do */
        return trie;
    }

    /* else */
    /* hard case---have to extend the trie */
    oldkey = t->key;
#ifdef EXCESSIVE_TIDINESS
    t->key = 0;      /* not required but makes data structure look tidier */
#endif

    /* walk the common prefix */
    while(GET_BIT(oldkey, bit) == (bitvalue = GET_BIT(key, bit))) {
        kid = make_trie_node(0);
        t->kids[bitvalue] = kid;
        bit++;
        t = kid;
    }

    /* then split */
    t->kids[bitvalue] = make_trie_node(key);
    t->kids[!bitvalue] = make_trie_node(oldkey);

    return trie;
}

/* kill it */
void
trie_destroy(Trie trie)
{
    int i;

    if(trie) {
        for(i = 0; i < TRIE_BASE; i++) {
            trie_destroy(trie->kids[i]);
        } 

        if(IsLeaf(trie)) {
            free(trie->key);
        }

        free(trie);
    }
}

