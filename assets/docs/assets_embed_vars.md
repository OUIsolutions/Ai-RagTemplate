# Assets Embed Variables

Assets in the context of this project represent individual files within the `/assets` directory. These files are listed recursively to capture all assets present in the directory. The assets are then saved and managed as part of the build process by the `create_assets.lua` script.

## Asset Structure

The `Asset` struct defined in `types.assets.h` encapsulates the properties of an asset file:
- **path**: The file path of the asset.
- **data**: Pointer to the content of the asset.
- **size**: Size of the asset's content.

## Functions

### `get_asset`

Retrieve an asset by providing its file path.
```c
Asset *get_asset(const char *path);
```

### `list_assets_recursively`

List all assets recursively within a specified directory path.
```c
DtwStringArray *list_assets_recursively(const char *path);
```

### `list_assets`

List all assets within a given directory path.
```c
DtwStringArray *list_assets(const char *path);
```

For further details on the implementation and usage of assets in the project, refer to the corresponding `fdeclare.assets.h` and `types.assets.h` files.