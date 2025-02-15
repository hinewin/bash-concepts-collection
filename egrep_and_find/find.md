
- `start_dir`: Optional starting directory (default is current directory)
- `criteria_list`: One or more search criteria

## Search Criteria

### File Attributes

1. **Name**:
   - `-name filename`: Exact match
   - `-name 'pattern'`: Wildcard match (use quotes)
   - `-iname`: Case-insensitive name match

2. **Type**:
   - `-type d`: Directories
   - `-type f`: Regular files
   - `-type l`: Symbolic links

3. **Size**:
   - `-size +Nc`: Larger than N bytes
   - `-size -NM`: Smaller than N megabytes
   - `-size Nk`: Exactly N kilobytes

4. **Permissions**:
   - `-perm mode`: Exact permission mode

5. **Time**:
   - `-mtime +n`: Modified more than n days ago
   - `-mtime -n`: Modified less than n days ago
   - `-mmin +n`: Modified more than n minutes ago

### Advanced Criteria

- `-empty`: Empty files or directories
- `-inum number`: Files with specific inode number
- `-links n`: Files with n hard links
- `-lname pattern`: Symbolic links matching pattern

## Limiting Search Depth

- `-maxdepth n`: Limit search to n levels below start directory

## Combining Criteria

- AND: List criteria separated by spaces
- OR: Use `-o` between criteria

## Actions

### Default Action

- Prints the path of matched files

### exec Option

`find start_dir criteria -exec command {} \;
`

- Executes `command` on each found file
- `{}` represents the found file
- `\;` terminates the command

### Using xargs

`find start_dir criteria | xargs command`

- Passes found files to `command` in batches
```bash
find -type f -name 'module*' | xargs mv -t module/
# -t is needed to specify a target dir
# Without -t, xargs would mv file1 file2 file3 module
```
### Xargs `-I{}`

The `-I` option in xargs is used to specify a placeholder for the input arguments. It's particularly useful when you need to control where the arguments are placed in the command.

```bash
xargs -I{} command {}
```

The `{}` is now a placeholder, You can use any string instead of `{}` such as `I@`
```bash
find -type f -name 'module*' | xargs -I{} mv {} module/
```

## Best Practices

- Use quotes for wildcard patterns
- Combine criteria for precise searches
- Use `-maxdepth` to limit recursive depth when necessary
- Prefer `xargs` for better performance with multiple files


