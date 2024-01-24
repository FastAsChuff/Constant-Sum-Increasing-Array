//================================================================================================================
//  Use these functions to iterate over all (non-strictly) increasing arrays of buckets (>0) non-negative integer
//  elements which have constant sum sum. Caller must free array if the iterations are abandoned early.
//  Author: Simon Goater Jan 2024
// Motivated by https://stackoverflow.com/questions/77854835/how-to-calculate-the-number-of-ways-to-choose-y-items-from-at-most-x-groups-effi#77854835
//================================================================================================================
_Bool constsumincarr_next(uint32_t buckets, uint32_t *constsumincarr) {
  int32_t j, i = buckets-2;
  while ((i >= 0) && (1+constsumincarr[i] >= constsumincarr[buckets-1])) i--;
  if (i < 0) {
    free(constsumincarr);
    return false;
  }
  constsumincarr[i]++;
  constsumincarr[buckets-1]--;
  j = i+1;
  while (j < buckets-1) {
    constsumincarr[buckets-1] += constsumincarr[j] - constsumincarr[i];
    constsumincarr[j] = constsumincarr[i];
    j++;
  }
  return true;
}

uint32_t *constsumincarr_init(uint32_t buckets, uint32_t sum) {
  if (buckets == 0) return NULL;
  if (buckets >> 31 != 0) return NULL;
  uint32_t *constsumincarr = calloc(buckets, sizeof(uint32_t));  
  if (constsumincarr == NULL) return NULL;
  constsumincarr[buckets-1] = sum;
  return constsumincarr;
}

