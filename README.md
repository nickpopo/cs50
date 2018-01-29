# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

According to Merriam-Webster's Medical Dictionary,
pneumonoultramicroscopicsilicovolcanoconiosis is a
pneumoconiosis caused by inhalation of very fine
silicate or quartz dust.

## According to its man page, what does `getrusage` do?

returns resource usage measures statistics for the calling process, which is the sum of resources used by all threads in the process.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16 members.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Better style and clear code and if we pass by reference we have to pass just 2 parameters, but if by value - 8.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Reads words by character, the word that comes to check can not be more than 45 characters, and words with numbers are completely ignored. When it is considered that the word is fully read, it insert a new line character into array "word", then the array pass to function checking.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

If we would used fscanf then we would have to first remember each readed word, then separately check it for compliance with the necessary conditions and only then submit to the check function, but when we read the words character-by-character, we can, at the reading stage, eliminate the unnecessary words.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

In order to prevent changes of data's value.
