

times = {
    "ulazak": 10,
    "ponavljanje": [5, 2, 2],
    "moj govor": [7, 4, 2],
    "zadaci1": [10, 10, 10],
    "moj govor: brzina": [2, 5, 5, 5],
    "zadaci2": [10, 10, 10]
}

cumulative = 0
for key, value in times.items():
    total = sum(value) if isinstance(value, list) else value
    cumulative += total
    print(f"* {key}: {total} min")
    print(f"   cum. = {cumulative} min")
