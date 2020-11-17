#ifndef COMPACTION_H
#define COMPACTION_H

/**
 * Compacts a string by grouping together repeated chars
 * @param word string to compact
 * @returns compacted word
 */
const char *prog(const char *word);

/**
 * Compacts a string by grouping together repeated patterns
 * @param word string to compact
 * @returns compacted word
 */
const char *prog2(const char *word);

/**
 * Reverses the processing of functions prog and prog2
 * Inflates a string using the patterns or single chars
 * followed by a number that describes how many times
 * they repeat themselves
 * @param word string to uncompact
 * @returns uncompacted word
 */
const char *desprog(const char *word);

#endif //COMPACTION_H
